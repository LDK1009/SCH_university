package 자바실습_20194463_이동규;
import java.util.Scanner;
public class practice_p110_Num3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int moneynum;
		System.out.print("금액을 입력하세요 : ");
		int money = scanner.nextInt();
		switch (money/50000) {
		default:
			moneynum = money/50000;
			System.out.println("오만원 : "+ moneynum + "개");
			money = money%50000;
		case 0:
			switch (money/10000) {
			default:
				moneynum = money/10000;
				System.out.println("만원 : "+ moneynum + "개");
				money = money%10000;
			case 0:
				switch (money/1000) {
				default:
					moneynum = money/1000;
					System.out.println("천원 : "+ moneynum + "개");
					money = money%1000;
				case 0:
					switch (money/500) {
					default:
						moneynum = money/500;
						System.out.println("오백원 : "+ moneynum + "개");
						money = money%500;
					case 0:
						switch (money/100) {
						default:
							moneynum = money/100;
							System.out.println("백원 : "+ moneynum + "개");
							money = money%100;
						case 0:
							switch (money/50) {
							default:
								moneynum = money/50;
								System.out.println("오십원 : "+ moneynum + "개");
								money = money%50;
							case 0:
								switch (money/10) {
								default:
									moneynum = money/10;
									System.out.println("십원 : "+ moneynum + "개");
									money = money%10;
								case 0:
									switch (money/1) {
									default:
										moneynum = money/1;
										System.out.println("일원 : "+ moneynum + "개");
										money = money%1;
									case 0:
										break;
									}}}}}}}}
				scanner.close();
				}
		}
					

		

	

