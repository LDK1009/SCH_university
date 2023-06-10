import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;

public class my08_11 {

    public static void findWord(Vector<String> v, String word) {
        int i = 0;
        while (i < v.size()) {
            if (v.get(i).contains(word))
                System.out.println(v.get(i));
            i++;
        }
    }

    public static void main(String[] args) {
        FileReader fr = null;
        BufferedReader br = null;
        try {
            File f = new File("C:\\Users\\이동규\\Desktop\\이동규\\SCH_university\\컴퓨터소프트웨어공학과\\2023-1\\자바 프로그래밍 실습\\소스코드\\src\\Practice\\PracticeAnswer\\08장\\chap08-prac11\\words.txt");
            fr = new FileReader(f);
            br = new BufferedReader(fr);

            Vector<String> v = new Vector<String>();
            Scanner scanner = new Scanner(System.in);
            String word = null;

            while (br.readLine() != null) {
                v.add(br.readLine());
            }

            System.out.println("프로젝트 폴터 밑의" + f.getPath() + " 파일을 읽었습니다");
            while (word != "그만") {
                System.out.println("단어>>");
                word = scanner.nextLine();
                findWord(v, word);

            }

        } catch (IOException e) {
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
