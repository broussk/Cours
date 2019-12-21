import javax.swing.JFrame;
import java.awt.Dimension;

public class MyJFrame extends JFrame
{
    private static final long serialVersionUID = 222222222222L;
    
    public MyJFrame()
    {
	Dimension resolution=this.getToolkit().getScreenSize();
	Dimension dimension=this.getSize();
	
	this.setSize(new Dimension(500,500));

	this.setLocation((int)(resolution.getWidth()/2-dimension.getWidth()/2),(int)(resolution.getHeight()/2-dimension.getHeight()/2));

	this.setTitle("Exemple de dessin");
	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	this.getContentPane().add(new MyJLabel(0));
	
	this.setVisible(true);
    }
}
