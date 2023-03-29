package 자바실습;
import java.util.Scanner;

public class practice_0323 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a, b;
		int sum;
		Scanner scanner=new Scanner(System.in);
		System.out.println("양수 a, b를 입력하십시오");
		a=scanner.nextInt();
		b=scanner.nextInt();
		for(int i =a; i<b; i++)
		{
			if((i%3)==0)
				sum += i; 
		}
		System.out.println(a+"부터"+"b까지의 수 중 3배수의 합은"+sum+"입니다.");
		
		
	}

}
