public class Circle {

    private int x, y;

    private float z;

    public Circle(int x, int y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void equals(Circle diffrent) {
        if ((x == diffrent.x) && (y == diffrent.y)) {
            System.out.println("같은 원");
        } else {
            System.out.println("다른 원");
        }
        //        return ( (this.x == diffrent.x) && (this.y == diffrent.y) );
    }

    public Circle() {
        x = 0;
        y = 0;
        z = 0;

    }

    public static void main(String[] args) {
        Circle a = new Circle(1, 1, 5);
        Circle b = new Circle(1, 1, 10);
        a.equals(b);


    }
}