package theSurvivor;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.BoxLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.awt.Toolkit;
import java.awt.Dimension;

import java.util.Vector;

class TheSurvivorConfiguration extends JFrame
{
    public static final long serialVersionUID=1111;

    protected BoxLayout layout;
    protected JPanel mainPanel=new JPanel();
    protected JPanel panelBoutons=new JPanel();
    protected JButton boutonValider=new JButton("Valider");
    protected JButton boutonQuitter=new JButton("Quitter");
    protected Toolkit toolkit;
    protected Dimension screenSize;

    private TheSurvivorWindows theSurvivorWindows;
    public static final int WIDTH=400;
    public static final int HEIGHT=150;
 
    TheSurvivorConfiguration()
    {
	setTitle("TheSurvivor Configuration");

	addActions();
	
	layout=new BoxLayout(mainPanel,BoxLayout.Y_AXIS);
	mainPanel.setLayout(layout);

	panelBoutons.add(boutonValider);
	panelBoutons.add(boutonQuitter);

	mainPanel.add(panelBoutons);

	getContentPane().add(mainPanel);
	
	setDefaultCloseOperation(EXIT_ON_CLOSE);
	toolkit=Toolkit.getDefaultToolkit();
	screenSize=toolkit.getScreenSize();
	
	setSize(WIDTH,HEIGHT);
	setLocation((int)((screenSize.getWidth()/2)-getWidth()/2),(int)((screenSize.getHeight()/2)-getHeight()/2));
	setResizable(false);
	setVisible(true);

	theSurvivorWindows=new TheSurvivorWindows(this,10,10);
		
    }

    void reactivate()
    {
	setVisible(true);
    }

    private void addActions()
    {
	boutonQuitter.addActionListener(new ExitAction());
	boutonValider.addActionListener(new ActionListener() 
	    {
		public void actionPerformed(ActionEvent ev)
		{
		    setVisible(false);
		    theSurvivorWindows.init();
		}
	    });

    }
}