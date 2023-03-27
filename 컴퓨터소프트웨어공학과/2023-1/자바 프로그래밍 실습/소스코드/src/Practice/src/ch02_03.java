import java.util.Scanner;

public class ch02_03 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("금액을 입력하시오>>");
		int Money = scanner.nextInt();
		int MoneyDivide [] = {50000, 10000, 5000, 1000, 100, 50, 10, 1};
		
		for(int i=0; i<MoneyDivide.length; i++)
		{
			int DivideNum= Money / MoneyDivide[i];
			System.out.println(MoneyDivide[i] + "권 " + DivideNum + " 개");
			Money %= MoneyDivide[i];
		}
	}

}
