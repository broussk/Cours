import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.GridLayout;
import java.awt.BorderLayout;

public class Morpion
{
    public static void main(String[] args)
    {
	JFrame windows = new JFrame();

	JPanel panel=new JPanel();
	JPanel zone=new JPanel();

	zone.setLayout(new GridLayout(3,3));
	panel.setLayout(new BorderLayout());

	for(int i=0;i<9;i++)
	    {
		zone.add(new JButton("X"));
	    }
	
	panel.add(new JButton("Partie 1"),BorderLayout.NORTH);
	panel.add(new JButton("Joueur 1"),BorderLayout.WEST);
	panel.add(zone); // BorderLayout.CENTER non nécessaire
	panel.add(new JButton("Score"),BorderLayout.EAST);
	panel.add(new JButton("Morpion"),BorderLayout.SOUTH);
	
	windows.getContentPane().add(panel);

	windows.setSize(new Dimension(400,200));
	
	Dimension resolution=windows.getToolkit().getScreenSize();
	Dimension dimension=windows.getSize();

	windows.setLocation((int)(resolution.getWidth()/2-dimension.getWidth()/2),(int)(resolution.getHeight()/2-dimension.getHeight()/2));

	windows.setTitle("Morpion");
	windows.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	windows.setVisible(true);
    }
}
