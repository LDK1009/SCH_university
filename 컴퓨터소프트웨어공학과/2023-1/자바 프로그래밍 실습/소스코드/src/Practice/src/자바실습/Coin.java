package �ڹٽǽ�;
import java.util.Scanner;
public class Coin {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.print("������ �Է��Ͻÿ� :");
		int money = scanner.nextInt();
		int a = 0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;		
		if(money>=50000)
		{
			a=money/50000;
			money=money%50000;
			System.out.println("��������" + a + "��");
		}
		if(money>=10000)
		{
			b=money/10000;
			money=money%10000;
			System.out.println("������" + b + "��");
		}
		if(money>=1000)
		{
			c=money/1000;
			money=money%1000;
			System.out.println("õ����" + c + "��");
		}
		if(money>=500)
		{
			d=money/500;
			money=money%500;
			System.out.println("�����" + d + "��");
		}
		if(money>=100)
		{
			e=money/100;
			money=money%100;
			System.out.println("���" + e + "��");
		}
		if(money>=50)
		{
			f=money/50;
			money=money%50;
			System.out.println("���ʿ�" + f + "��");
		}
		if(money>=10)
		{
			g=money/10;
			money=money%10;
			System.out.println("�ʿ�" + g + "��");
		}
		if(money>=1)
		{
			h=money/1;
			money=money%1;
			System.out.println("�Ͽ�" + h + "��");
		}

		scanner.close();
	}
}
