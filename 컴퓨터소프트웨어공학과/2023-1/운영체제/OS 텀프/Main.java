import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        int time;

        ArrayList<Process> process_list = new ArrayList<Process>();

        BufferedReader inFile = new BufferedReader(new FileReader("./input.txt"));
        String sLine = null;

        while( (sLine = inFile.readLine()) != null ) {
            StringTokenizer st = new StringTokenizer(sLine);
            String processName = st.nextToken();
            int arrivalTime = Integer.parseInt(st.nextToken());
            int serviceTime = Integer.parseInt(st.nextToken());
            int priority = Integer.parseInt(st.nextToken());

            Process p = new Process(processName, arrivalTime, serviceTime, priority);
            process_list.add(p);
        }

        time = 2;

        FCFS f = new FCFS();
        System.out.println("\nFCFS");
        f.insertSchedule(process_list);

        SJF s = new SJF();
        System.out.println("\nSJF");
        s.insertSchedule(process_list);

        NoPrio np = new NoPrio();
        System.out.println("\nNP Priority");
        np.insertSchedule(process_list);

        PrPrio pp = new PrPrio();
        System.out.println("\nP Priority");
        pp.insertSchedule(process_list);

        RR r = new RR();
        System.out.println("\nRR");
        r.insertSchedule(process_list, time);

        SRT rt = new SRT();
        System.out.println("\nSRT ");
        rt.insertSchedule(process_list, time);

        HRN h = new HRN();
        System.out.println("\nHRN");
        h.insertSchedule(process_list);
    }
}