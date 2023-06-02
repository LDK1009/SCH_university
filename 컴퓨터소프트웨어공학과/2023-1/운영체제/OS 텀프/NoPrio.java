import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class NoPrio {
    private int time = 0;
    private double responses = 0;
    private double waits = 0;
    private double returns = 0;
    private int size;
    private boolean usages = false;
    private List<Process> rq = new CopyOnWriteArrayList<>();
    private List<Process> q = new CopyOnWriteArrayList<>();
    
    void insertSchedule(ArrayList<Process> processes) {
        for (Process p : processes) {
            p.waitTime = 0;
            p.responseTime = -1;
            p.returnTime = 0;
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

    void startSchedule(Process p, int index) {
        int cpuCount = 0;
        usages = true;
        rq.remove(index);
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
        changeReadyQueue(GetPriIndex());
    }

    void addReadyQueue() {
        for (Process p : rq) {
            p.waitTime++;
        }
    }

    void changeReadyQueue(int index) {
        if (!usages && rq.size() != 0) {
            if (rq.get(index).responseTime == -1)
                rq.get(index).responseTime = time - rq.get(index).arrivalTime;
            startSchedule(rq.get(index), index);
        } else
            Queue();
    }

    int GetPriIndex() {
        int minSize = 0;
        for (int i = 1; i < rq.size(); i++) {
            if (rq.get(i).priority < rq.get(minSize).priority)
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
            changeReadyQueue(GetPriIndex());
        } else if (!usages) {
            System.out.println(time + "s : " + "Nothing runs");
            time++;
            Queue();
        }
    }
}
