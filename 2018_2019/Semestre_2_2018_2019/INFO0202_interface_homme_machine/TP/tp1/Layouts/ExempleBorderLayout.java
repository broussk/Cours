import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.BorderLayout;

public class ExempleBorderLayout
{
    public static void main(String[] args)
    {
	JFrame windows = new JFrame();

	JPanel panel=new JPanel();

	panel.setLayout(new BorderLayout());

	panel.add(new JButton("le nord"),BorderLayout.NORTH);
	panel.add(new JButton("l'ouest"),BorderLayout.WEST);
	panel.add(new JButton("le centre")); // BorderLayout.CENTER non nécessaire
	panel.add(new JButton("l'est"),BorderLayout.EAST);
	panel.add(new JButton("le sud"),BorderLayout.SOUTH);

	windows.getContentPane().add(panel);

	windows.setSize(new Dimension(400,200));
	
	Dimension resolution=windows.getToolkit().getScreenSize();
	Dimension dimension=windows.getSize();

	windows.setLocation((int)(resolution.getWidth()/2-dimension.getWidth()/2),(int)(resolution.getHeight()/2-dimension.getHeight()/2));

	windows.setTitle("Exemple de "+panel.getLayout().getClass().getName());
	windows.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	windows.setVisible(true);
    }
}


