package �ڹٽǽ�;
import java.util.Scanner;
public class Triangle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.print("���� 3�� �Է� :");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c = scanner.nextInt();
		if(a<b+c && b<a+c && c<a+b )
		{
			System.out.println("�ﰢ���� �˴ϴ�");
		}
		else
		{
			System.out.println("�ﰢ���� �ȵ˴ϴ�");
		}
		scanner.close();
	}
}
