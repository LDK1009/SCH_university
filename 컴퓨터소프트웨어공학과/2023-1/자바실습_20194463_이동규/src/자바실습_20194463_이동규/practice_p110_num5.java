package 자바실습_20194463_이동규;
import java.util.Scanner;
public class practice_p110_num5 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("세 변의 길이를 입력하세요 : ");
		int x  = scanner.nextInt(); // scanner.nextInt()는 자동으로 줄바꿈과 공백을 인식하여 버퍼에 입력 및 변수 저장을 한다.
		int y  = scanner.nextInt();
		int z  = scanner.nextInt();

		switch ((x+y)/z){
		case 1:
			System.out.print("삼각형을 만들 수 있습니다.");
			break;
		default:
			switch ((y+z)/x){
				case 1:
					System.out.print("삼각형을 만들 수 있습니다.");
					break;
				default:
					switch ((x+z)/y){
					case 1:
						System.out.print("삼각형을 만들 수 있습니다.");
						break;
					default:
						System.out.print("삼각형을 만들 수 없습니다.");
						break;
				}
			}
		}
	}
}
