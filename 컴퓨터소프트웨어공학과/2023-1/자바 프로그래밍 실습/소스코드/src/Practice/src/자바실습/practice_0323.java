package �ڹٽǽ�;
import java.util.Scanner;

public class practice_0323 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a, b;
		int sum;
		Scanner scanner=new Scanner(System.in);
		System.out.println("��� a, b�� �Է��Ͻʽÿ�");
		a=scanner.nextInt();
		b=scanner.nextInt();
		for(int i =a; i<b; i++)
		{
			if((i%3)==0)
				sum += i; 
		}
		System.out.println(a+"����"+"b������ �� �� 3����� ����"+sum+"�Դϴ�.");
		
		
	}

}
