import java.util.Scanner;

public class ch02_01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.println("원화를 입력하세요(단위 원)>>");
		int KRW = scanner.nextInt();
		float dollar = (KRW/1100);
		System.out.println(KRW+"는 $"+dollar+"입니다");

	}

}
