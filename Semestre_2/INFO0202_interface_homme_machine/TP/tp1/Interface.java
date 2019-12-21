import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.util.Vector;
import javax.swing.JComboBox;
public class Interface
{
    public static void main(String[] args)
    {
	JFrame windows = new JFrame();

	JPanel panel=new JPanel();
	JPanel panel2=new JPanel();
	panel.setLayout(new BorderLayout());
	
	Vector<String> couleurs = new Vector<String>();
	couleurs.add(" ");
	couleurs.add("X");
	couleurs.add("O");

	panel.add(new JButton("Nom joueur"),BorderLayout.NORTH);
	panel.add(new JButton("Morpion"),BorderLayout.WEST);
	
	panel2.setLayout(new GridLayout(3,3));
	for(int i=0;i<9;i++)
	    {
		panel2.add(new JComboBox<String>(couleurs));
	    }
	panel.add(new JButton("score"),BorderLayout.EAST);
	panel.add(new JButton("Partie 2"),BorderLayout.SOUTH);
	panel.add(panel2);
	JComboBox<String> component = new JComboBox<String>(couleurs);
	
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

