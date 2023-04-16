
public class ch03_02 {

	public static void main(String[] args) {
		int n [][] = {
				{1},
				{1,2,3},
				{1},
				{1,2,3,4},
				{1,2}				
		};



		// 출력

		for (int r=0; r<n.length; r++) {

			for (int c=0; c<n[r].length; c++) {

				System.out.print(n[r][c] + "\t");

			}

			System.out.println();

		}


		
	}

}
