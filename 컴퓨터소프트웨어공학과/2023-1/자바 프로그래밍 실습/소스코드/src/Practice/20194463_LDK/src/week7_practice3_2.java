
public class week7_practice3_2 extends week7_practice3	{
	private int z;
	

	public week7_practice3_2(int a, int b, int c)
	{
		super(a,b);
		this.z = c;
	}
	
	public int getZ()
	{
		return this.z;
	}
	
	public String toString()
	{
		String a = "("+super.getX() +","+super.getY()+","+ getZ() +")";
		return a;
	}
	
	public void move(int a, int b, int c)
	{
		super.move(a, b);
		this.z = c;
	}
	public void moveUP()
	{
		this.z +=1;
	}
	
	public void moveDOWN()
	{
		this.z -= 1;
	}
	public static void main(String[] args) 
	{
		
		
		week7_practice3_2 p = new week7_practice3_2(1,2,3);
		System.out.println(p.toString() + "입니다.");

		p.moveUP();
		System.out.println(p.toString() + "입니다.");
		
		p.moveDOWN();
		p.move(10,10);
		System.out.println(p.toString() + "입니다.");
		
		p.move(100, 200, 300);
		System.out.println(p.toString() + "입니다.");
	}

}
