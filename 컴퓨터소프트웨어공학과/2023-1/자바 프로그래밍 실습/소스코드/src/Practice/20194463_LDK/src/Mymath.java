import java.util.Scanner;
import java.util.Scanner;
public class Mymath {
	public float pi = (float)3.14;
	public float volume;
	
	public Mymath()
	{
		pi = (float)3.14;
	}
	
	
	
	public float CircleArea(int r)
	{
		this.volume = r*r*this.pi ;
		return this.volume;
	}
	
	public static void main(String[] args) {
				Scanner scanner = new Scanner(System.in);
				
				System.out.println("������ >>");
				int r = scanner.nextInt();
				
				Mymath MyCircle = new Mymath();
				
				System.out.println("������ : " + MyCircle.pi);
				System.out.println("���� : " + MyCircle.CircleArea(r));
			}

	}
