import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class SRT {
    private int time = 0;
    private double responses = 0;
    private double waits;
    private double returns;
    private int size;
    private boolean usages = false;
    private int timeSlicer = 0;
    private List<Process> rq = new CopyOnWriteArrayList<>();
    private List<Process> q = new CopyOnWriteArrayList<>();

    void insertSchedule(ArrayList<Process> processes, int timeSlicer) {
        this.timeSlicer = timeSlicer;

        for (Process p : processes) {
            p.waitTime = 0;
            p.responseTime = -1;
            p.returnTime = 0;
            p.timeRemain = p.serviceTime;
            q.add(p);
        }

        q.sort(Comparator.comparingInt(j -> j.arrivalTime));
        size = q.size();
        Queue();
    }

    void printRunning(Process p) {
        System.out.print(time + "s : " + p.ID + " is running [");
        for (Process process : rq) System.out.print(process.ID + " ");
        System.out.println("]");
    }

    void startSchedule(Process p) {
        int cpuCount = 0;
        usages = true;

        while (p.timeRemain != 0 && cpuCount != timeSlicer) {
            printRunning(p);
            cpuCount++;
            time++;
            addReadyQueue();
            p.timeRemain--;
            Queue();
        }

        if (p.timeRemain == 0) {
            rq.remove(0);
            p.returnTime = time - p.arrivalTime;
            returns += p.returnTime;
            responses += p.responseTime;
            waits += p.waitTime;

            System.out.println(p.ID + " 프로세스 응답 시간: " + p.responseTime +
                    " / 대기 시간: " + p.waitTime +
                    " / 반환 시간: " + p.returnTime);
        }
        usages = false;
        changeReadyQueue();
    }

    void addReadyQueue() {
        for (Process p : rq) {
            p.waitTime++;
        }
    }

    void changeReadyQueue() {

        if (!usages && rq.size() != 0) {
            if (rq.get(0).responseTime == -1) {
                rq.get(0).responseTime = time - rq.get(0).arrivalTime;
            } else {
                rq.sort(Comparator.comparingInt(time -> time.timeRemain));
            }
            startSchedule(rq.get(0));
        } else
            Queue();
    }


    void Queue() {
        if (q.size() == 0 && rq.size() == 0 && !usages) {
            System.out.println("평균 응답 시간: " + (responses / size) +
                    " / 평균 대기 시간 " + (waits / size) +
                    " / 평균 반환 시간 " + (returns / size));
            return;
        }

        if (q.size() != 0 && q.get(0).arrivalTime <= time) {
            rq.add(q.get(0));
            q.remove(0);
            changeReadyQueue();
        } else if (!usages) {
            System.out.println(time + "s : " + "Nothing runs");
            time++;
            Queue();
        }
    }
}