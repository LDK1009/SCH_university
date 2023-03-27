import java.util.Scanner; 

public class ch02_04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int num[]=new int [3];
		int middel = 0;
		System.out.println("정수 3개 입력>>");
		num[0] = scanner.nextInt();
		num[1] = scanner.nextInt();
		num[2] = scanner.nextInt();
		
		if(num[1]>num[0] && num[2]>num[1])
			middel = num[1];
		if(num[2]>num[1] && num[0]>num[2])
			middel = num[2];
		if(num[0]>num[2] && num[1]>num[0])
			middel = num[3];
		System.out.println("중간 값은 " + middel);
	}

}
