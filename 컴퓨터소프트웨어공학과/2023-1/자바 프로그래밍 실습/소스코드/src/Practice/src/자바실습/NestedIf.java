package ÀÚ¹Ù½Ç½À;
import java.util.Scanner;
public class NestedIf {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner= new Scanner(System.in);
		
		System.out.print("? ?ˆ˜ë¥? ?ž…? ¥?•˜?‹œ?˜¤(0~100): ");
		int score = scanner.nextInt();
		System.out.print("?•™?…„?„ ?ž…? ¥?•˜?‹œ?˜¤(1~4): ");
		int year = scanner.nextInt();
		
		if(score>=60) {
			if(year !=4)
				System.out.println("T");
			else if(score>=70)
				System.out.println("T");
			else 
				System.out.println("F");
		}
		else
			System.out.println("F");
		scanner.close();
	}

}
