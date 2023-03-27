import java.util.Scanner;

public class ch02_02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.println("두 자리 정수를 입력하세요(10~99)");
		int num = scanner.nextInt();
		int TenPlace = num / 10;
		int Oneplace = num % 10;
		if(TenPlace == Oneplace )
		{
			System.out.println("Yes! 10의 자리와 1의 자리가 같습니다.");
		}
		else
		{
			System.out.println("NO! 10의 자리와 1의 자리가 같지 않습니다.");
		}
	}

}
