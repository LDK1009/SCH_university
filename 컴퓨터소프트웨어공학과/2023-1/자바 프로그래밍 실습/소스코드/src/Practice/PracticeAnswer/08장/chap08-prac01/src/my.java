import java.io.*;
import java.util.Scanner;

public class my {

    public static void main(String[] args) {
        FileWriter fw = null;
        File f = new File("C:\\Users\\이동규\\Desktop\\my.txt");
        try {
            fw = new FileWriter(f);
            Scanner scanner = new Scanner(System.in);

            System.out.println("전화번호 입력 프로그램 입니다.");
            while (true) {
                System.out.println("이름 전화번호 >>");
                String inputLine = scanner.nextLine();
                if (inputLine.equals("그만")) {
                    break;
                }
                fw.write(inputLine + "\n");

            }
            System.out.println(f.getPath() + "에 저장하였습니다.");

            scanner.close();
            fw.close();


        } catch (IOException e) { // 파일을 저장할 수 없는 경우 예외
            e.printStackTrace();
        }

    }
}
