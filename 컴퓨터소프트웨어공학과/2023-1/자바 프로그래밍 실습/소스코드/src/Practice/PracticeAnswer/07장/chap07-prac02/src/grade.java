package src;

import java.util.Scanner;
import java.util.Vector;

import java.util.Scanner;

public class grade {
    private static float sum = 0;
    private static float aver = 0;

    public static void average(Vector<Character> v) {

        for (int i = 0; i < v.size(); i++) {
            switch (v.get(i)) {
                case 'a':
                case 'A':
                    sum += 4.0;
                    break;
                case 'b':
                case 'B':
                    sum += 3.0;
                    break;

                case 'c':
                case 'C':
                    sum += 2.0;
                    break;

                case 'd':
                case 'D':
                    sum += 1.0;
                    break;

                case 'f':
                case 'F':
                    sum += 0.0;
                    break;


            } // end of switch
        } //end of for
        aver = sum / v.size();
        System.out.println(aver);
    } // end of average

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Vector<Character> v = new Vector<Character>();

        System.out.println("6���� ������ �� ĭ���� �и� �Է� (A/B/C/D/F) >>");

        while (v.size() < 6) {
            char character;

            character = scanner.next().charAt(0);
            switch (character) {
                case 'a':
                case 'A':
                case 'b':
                case 'B':
                case 'c':
                case 'C':
                case 'd':
                case 'D':
                case 'f':
                case 'F':
                    break;
                default:
                    System.out.println("�߸� �Է� �ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
                    continue;
            }   // end of switch
            v.add(character);

        } // end of while

        average(v);


    }
}
