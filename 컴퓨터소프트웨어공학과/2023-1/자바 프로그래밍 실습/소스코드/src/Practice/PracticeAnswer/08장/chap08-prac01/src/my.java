import java.io.*;
import java.util.Scanner;

public class my {

    public static void main(String[] args) {
        FileWriter fw = null;
        File f = new File("C:\\Users\\�̵���\\Desktop\\my.txt");
        try {
            fw = new FileWriter(f);
            Scanner scanner = new Scanner(System.in);

            System.out.println("��ȭ��ȣ �Է� ���α׷� �Դϴ�.");
            while (true) {
                System.out.println("�̸� ��ȭ��ȣ >>");
                String inputLine = scanner.nextLine();
                if (inputLine.equals("�׸�")) {
                    break;
                }
                fw.write(inputLine + "\n");

            }
            System.out.println(f.getPath() + "�� �����Ͽ����ϴ�.");

            scanner.close();
            fw.close();


        } catch (IOException e) { // ������ ������ �� ���� ��� ����
            e.printStackTrace();
        }

    }
}
