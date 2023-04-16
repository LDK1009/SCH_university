import java.util.Scanner;

public class ch02_06 {

	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		System.out.println("1~99 사이의 정수를 입력하시오 >> ");
		int num = scanner.nextInt();
		int clapCount_10 = (num/10)/3;
		int clapCount_01 = (num%10)/3;
		
		if(clapCount_10 >= 1 && clapCount_01 >= 1)
		{
			System.out.println("박수짝짝");
		}
		else if(clapCount_10 >= 1 || clapCount_01 >= 1)
		{
			System.out.println("박수짝");
		}
	}

}
