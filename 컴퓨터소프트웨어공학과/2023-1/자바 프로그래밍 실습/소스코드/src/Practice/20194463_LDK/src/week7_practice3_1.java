
public class week7_practice3_1 extends week7_practice3 {
	
	String Color = "BLACK";
	
	public week7_practice3_1()
	{
		super(0, 0);
		// TODO Auto-generated constructor stub
	}
	
	public week7_practice3_1(int x, int y) {
		super(x, y);
		// TODO Auto-generated constructor stub
	}
	
	public void setXY(int a, int b)
	{
		super.move(a, b);
	}

	public void setColor(String inputColor)
	{
		this.Color = inputColor;
	}
	
	public String toString()
	{
		String info = this.Color + "색의 (" + super.getX() + " ," + super.getY() + ")의 점";
		return info;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		week7_practice3_1 zeroPoint = new week7_practice3_1();
		System.out.println(zeroPoint.toString()+"입니다.");
		
		week7_practice3_1 cp = new week7_practice3_1(10,10);
		cp.setXY(5,5);
		cp.setColor("RED");
		System.out.println(cp.toString() + "입니다.");
	}

}
