import java.util.Scanner;

public class ch02_05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int num[]=new int [3];
		int middel = 0;
		System.out.println("정수 3개 입력>>");
		for(int i=0; i<num.length; i++)
		{
			num[i] = scanner.nextInt();
		}
		
		if((num[0]+num[1]<num[2])||(num[2]+num[0]<num[1])||(num[1]+num[2]<num[0]))
			System.out.println("삼각형이 됩니다");
		else
			System.out.println("삼각형이 되지 못 합니다");
	}

}
