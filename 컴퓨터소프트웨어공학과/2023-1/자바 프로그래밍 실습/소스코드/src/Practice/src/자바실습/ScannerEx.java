package ÀÚ¹Ù½Ç½À;
import java.util.Scanner;
public class ScannerEx {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("?´ë¦?, ?„?‹œ, ?‚˜?´, ì²´ì¤‘, ?…?‹  ?—¬ë¶?ë¥? ë¹ˆì¹¸?œ¼ë¡? ë¶„ë¦¬?•˜?—¬ ?…? ¥?•˜?„¸?š”");
		Scanner scanner= new Scanner(System.in);
		
		String name = scanner.next();
		System.out.print("?´ë¦„ì?" + name + " , ");
		String city = scanner.next();
		System.out.print("?„?‹œ?Š”" + city + " , ");
		int age = scanner.nextInt();
		System.out.print("?‚˜?´?Š”" + age + "?‚´, ");
		double weight = scanner.nextDouble();
		System.out.print("ì²´ì¤‘??" + weight + "kg, ");
		boolean isSingle = scanner.nextBoolean();
		System.out.println("?…?‹  ?—¬ë¶??Š”" + isSingle + "?…?‹ˆ?‹¤.");
		
		scanner.close();
	}

}
