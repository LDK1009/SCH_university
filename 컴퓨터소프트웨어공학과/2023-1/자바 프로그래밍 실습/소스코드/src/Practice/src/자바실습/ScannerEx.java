package �ڹٽǽ�;
import java.util.Scanner;
public class ScannerEx {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("?���?, ?��?��, ?��?��, 체중, ?��?�� ?���?�? 빈칸?���? 분리?��?�� ?��?��?��?��?��");
		Scanner scanner= new Scanner(System.in);
		
		String name = scanner.next();
		System.out.print("?��름�?" + name + " , ");
		String city = scanner.next();
		System.out.print("?��?��?��" + city + " , ");
		int age = scanner.nextInt();
		System.out.print("?��?��?��" + age + "?��, ");
		double weight = scanner.nextDouble();
		System.out.print("체중??" + weight + "kg, ");
		boolean isSingle = scanner.nextBoolean();
		System.out.println("?��?�� ?���??��" + isSingle + "?��?��?��.");
		
		scanner.close();
	}

}
