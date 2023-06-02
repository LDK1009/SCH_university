import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;


public class HRN {
    private int time = 0;
    private double responses = 0;
    private double waits;
    private double returns;
    private int size;
    private boolean usages = false;
    private final List<Process> rq = new CopyOnWriteArrayList<>();
    private final List<Process> q = new CopyOnWriteArrayList<>();


    void insertSchedule(ArrayList<Process> processes) {
        for (Process p : processes) {
            p.waitTime = 0;
            p.responseTime = -1;
            p.returnTime = 0;
            p.HRNPriority = 0;
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
        rq.remove(0);

        while (cpuCount != p.serviceTime) {
            printRunning(p);
            cpuCount++;
            time++;
            addReadyQueue();
            Queue();
        }
        p.returnTime = time - p.arrivalTime;
        returns += p.returnTime;
        responses += p.responseTime;
        waits += p.waitTime;
        System.out.println(p.ID + " 프로세스 응답 시간: " + p.responseTime +
                " / 대기 시간: " + p.waitTime +
                " / 반환 시간: " + p.returnTime);
        usages = false;

        changeReadyQueue();

    }

    void addReadyQueue() {
        for (Process p : rq) {
            p.waitTime++;
        }
    }

    void changeReadyQueue() {
        for (Process a : rq) {
            a.HRNPriority = (time - a.arrivalTime) + 1;
        }
        rq.sort(Comparator.comparingDouble(j -> j.HRNPriority));

        if (!usages && rq.size() != 0) {
            if (rq.get(0).responseTime == -1)
                rq.get(0).responseTime = time - rq.get(0).arrivalTime;
            startSchedule(rq.get(0));
        } else
            Queue();
    }

    int GetPriIndex() {
        int minSize = 0;
        for (int i = 1; i < rq.size(); i++) {
            if (rq.get(i).HRNPriority < rq.get(minSize).HRNPriority)
                minSize = i;
        }
        return minSize;
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