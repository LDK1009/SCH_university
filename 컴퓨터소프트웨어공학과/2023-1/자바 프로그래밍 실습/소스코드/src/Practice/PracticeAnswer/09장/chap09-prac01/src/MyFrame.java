import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
    public MyFrame() {
        setTitle("¾ßÈ£");
        setSize(400, 200);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container contenPane = getContentPane();

        contenPane.setLayout(new BorderLayout());
        contenPane.setBackground(Color.RED);
        contenPane.add(new JButton("1"), BorderLayout.WEST);
        contenPane.add(new JButton("2"), BorderLayout.EAST);
        contenPane.add(new JButton("3"), BorderLayout.NORTH);
    }

    public static void main(String[] args) {
        new MyFrame();
    }

}
