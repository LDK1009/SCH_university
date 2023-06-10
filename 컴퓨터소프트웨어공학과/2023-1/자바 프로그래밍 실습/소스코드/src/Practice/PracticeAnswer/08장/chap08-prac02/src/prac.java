import java.io.*;

public class prac {

    public static void main(String[] args) {
        FileReader fr = null;
        BufferedReader br = null;

        try {
            File f = new File("C:\\Users\\이동규\\Desktop\\my.txt");
            fr = new FileReader(f);
            br = new BufferedReader(fr);

            String line;
            System.out.println("파일 내용:");
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException e) { // 파일을 읽을 수 없는 경우 예외
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
