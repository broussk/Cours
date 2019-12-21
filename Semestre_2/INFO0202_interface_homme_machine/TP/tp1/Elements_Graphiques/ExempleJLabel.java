import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Dimension;
import java.awt.Toolkit;

public class ExempleJLabel
{
    public static void main(String[] args)
    {
	JFrame windows = new JFrame("Exemple de JLabel");

	JLabel component = new JLabel("Hello World !!!");
	
	windows.getContentPane().add(component);
	windows.setSize(new Dimension(300,200));
	
	Dimension resolution=windows.getToolkit().getScreenSize();
	Dimension dimension=windows.getSize();
	windows.setLocation((int)(resolution.getWidth()/2-dimension.getWidth()/2),(int)(resolution.getHeight()/2-dimension.getHeight()/2));

	windows.setTitle("Exemple de "+component.getClass().getName());
	windows.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	windows.setVisible(true);
    }
}