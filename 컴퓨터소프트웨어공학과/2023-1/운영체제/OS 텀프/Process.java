public class Process {
    Process(String ID, int arrivalTime, int serviceTime, int priority) {
        this.ID = ID;
        this.arrivalTime = arrivalTime;
        this.serviceTime = serviceTime;
        this.priority = priority;
    }

    String ID;
    int arrivalTime;
    int serviceTime;
    double priority;
    double HRNPriority;
    int waitTime = 0;
    int responseTime = -1;
    int returnTime = 0;
    int timeRemain = 0;
}