import java.io.*;

public class prac {

    public static void main(String[] args) {
        FileReader fr = null;
        BufferedReader br = null;

        try {
            File f = new File("C:\\Users\\�̵���\\Desktop\\my.txt");
            fr = new FileReader(f);
            br = new BufferedReader(fr);

            String line;
            System.out.println("���� ����:");
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException e) { // ������ ���� �� ���� ��� ����
            e.printStackTrace();
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
                if (fr != null) {
                    fr.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
