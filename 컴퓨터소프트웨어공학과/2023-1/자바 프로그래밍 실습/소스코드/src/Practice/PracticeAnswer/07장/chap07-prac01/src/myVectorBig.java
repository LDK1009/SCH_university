import java.util.Scanner;
import java.util.Vector;


public class myVectorBig {

    public static void findBig(Vector<Integer> v) {
        int big = 0;
        for (int i = 0; i < v.size(); i++) {
            if (big < v.get(i)) {
                big = v.get(i);
            }
        }
        System.out.println(" ���� ū ���� " + big );

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Vector<Integer> V = new Vector<Integer>();


        System.out.println("���� -1�� �Էµ� ������ >>");

        while (true) {
            int num = scanner.nextInt();

            if (num == -1) {
                findBig(V);
                break;
            }

            V.add(num);

        }
    }


}
