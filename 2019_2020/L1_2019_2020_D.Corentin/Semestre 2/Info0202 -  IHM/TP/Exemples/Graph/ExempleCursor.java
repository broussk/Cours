import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.Cursor;

public class ExempleCursor
{
    public static void main(String[] args)
    {
	JFrame windows = new JFrame();

	JButton component = new JButton("OK");
	Cursor cursor=Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR);
	component.setCursor(cursor);

	windows.getContentPane().add(component);
	windows.setSize(new Dimension(300,200));
	
	Dimension resolution=windows.getToolkit().getScreenSize();
	Dimension dimension=windows.getSize();

	windows.setLocation((int)(resolution.getWidth()/2-dimension.getWidth()/2),(int)(resolution.getHeight()/2-dimension.getHeight()/2));

	windows.setTitle("Exemple de "+cursor.getClass().getName());
	windows.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	windows.setVisible(true);
    }
}