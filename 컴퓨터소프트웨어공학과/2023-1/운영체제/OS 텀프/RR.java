import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class RR {
    private int time = 0;
    private double responses = 0;
    private double waits;
    private double returns;
    private int size;
    private boolean usages = false;
    private int timeSlicer = 0;
    private int count = 0;
    private final List<Process> rq = new CopyOnWriteArrayList<>();
    private final List<Process> q = new CopyOnWriteArrayList<>();

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
        System.out.println("] " + count);
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
        count++;
        if (p.timeRemain == 0) {
            rq.remove(count - 1);

            p.returnTime = time - p.arrivalTime;
            returns += p.returnTime;
            responses += p.responseTime;
            waits += p.waitTime;

            System.out.println(p.ID + " 프로세스 응답 시간: " + p.responseTime +
                    " / 대기 시간: " + p.waitTime +
                    " / 반환 시간: " + p.returnTime);
            count--;
            Queue();

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
        if (count >= rq.size())
            count = 0;

        if (!usages && rq.size() != 0) {
            if (rq.get(count).responseTime == -1) {
                System.out.println(rq.get(count).ID + "응답시간 체점");
                rq.get(count).responseTime = time - rq.get(count).arrivalTime;
            }
            startSchedule(rq.get(count));
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