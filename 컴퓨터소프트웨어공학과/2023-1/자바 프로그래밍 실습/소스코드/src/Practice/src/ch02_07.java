import java.util.Scanner;

public class ch02_07 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rectX1 = 100, rectx2 = 200, recty1 = 100, recty2 = 200;
		System.out.println("점(x,y)의 좌표를 입력하시오.");
		int x = scanner.nextInt(), y = scanner.nextInt();
		if ((x > rectX1 && x < rectx2) && (y > recty1 && y < recty2))
		{
			System.out.println("(" + x + "," + y + ")" + "는 사각형 안에 있습니다");

		}

	}

}
