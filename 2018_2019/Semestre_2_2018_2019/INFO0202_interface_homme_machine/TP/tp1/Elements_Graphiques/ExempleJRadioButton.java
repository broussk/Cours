import javax.swing.JFrame;
import javax.swing.ButtonGroup;
import javax.swing.JRadioButton;
import javax.swing.JPanel;
import java.awt.Dimension;
import java.awt.Toolkit;

public class ExempleJRadioButton
{
    public static void main(String[] args)
    {
	JFrame windows = new JFrame("Exemple de JRadioButton");

	ButtonGroup groupe =  new ButtonGroup();
	
	JRadioButton jRadioButton1 = new JRadioButton("Choix 1");
	JRadioButton jRadioButton2 = new JRadioButton("Choix 2");
	JRadioButton jRadioButton3 = new JRadioButton("Choix 3");
	
	jRadioButton2.setSelected(true);
	
	groupe.add(jRadioButton1);
	groupe.add(jRadioButton2);
	groupe.add(jRadioButton3);
	
	JPanel panel=new JPanel();

	panel.add(jRadioButton1);
	panel.add(jRadioButton2);
	panel.add(jRadioButton3);

	windows.getContentPane().add(panel);
	windows.setSize(new Dimension(400,200));
	
	Dimension resolution=windows.getToolkit().getScreenSize();
	Dimension dimension=windows.getSize();

	windows.setLocation((int)(resolution.getWidth()/2-dimension.getWidth()/2),(int)(resolution.getHeight()/2-dimension.getHeight()/2));

	windows.setTitle("Exemple de "+jRadioButton1.getClass().getName());
	windows.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	windows.setVisible(true);
    }
}