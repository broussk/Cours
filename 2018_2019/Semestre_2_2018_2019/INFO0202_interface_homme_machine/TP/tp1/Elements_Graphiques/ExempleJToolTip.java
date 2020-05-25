import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JToolTip;
import java.awt.Dimension;
import java.awt.Toolkit;

public class ExempleJToolTip
{
    public static void main(String[] args)
    {
	JFrame windows = new JFrame("Exemple de JTextField");

	JLabel component = new JLabel("Hello World !!!");
	component.setToolTipText("ARRETEZ DE ME REGARDER !!!! VOYEUR !!!!");
	windows.getContentPane().add(component);
	windows.setSize(new Dimension(400,200));
	
	Dimension resolution=windows.getToolkit().getScreenSize();
	Dimension dimension=windows.getSize();
	windows.setLocation((int)(resolution.getWidth()/2-dimension.getWidth()/2),(int)(resolution.getHeight()/2-dimension.getHeight()/2));

	windows.setTitle("Exemple de "+new JToolTip().getClass().getName());
	windows.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	windows.setVisible(true);
    }
}