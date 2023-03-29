package 자바실습;
import java.util.Scanner;
public class Grading {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char grade;
		Scanner scanner= new Scanner(System.in);
		
		System.out.print("?젏?닔瑜? ?엯?젰?븯?떆?삤(0~100): ");
		int score = scanner.nextInt();
		if(score>=90)
			grade='A';
		else if(score>=80)
			grade='B';
		else if(score>=70)
			grade='C';
		else if(score>=60)
			grade='D';
		else
			grade='F';
		System.out.print("?븰?젏??" + grade +"?엯?땲?떎.");
		scanner.close();
	}

}
