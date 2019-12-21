package theSurvivor;

import javax.swing.JFrame;
import javax.swing.JMenuItem;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.BoxLayout;


import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import java.awt.Toolkit;
import java.awt.Dimension;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.Graphics;
import java.awt.Color;

class TheSurvivorWindows extends JFrame
{
    public static final long serialVersionUID=1000;

    public static final int HEIGHT=400;
    public static final int WIDTH=700;
    

    protected JMenuItem jmi_NouvellePartie=new JMenuItem("Nouvelle partie");
    protected JMenuItem jmi_Quitter=new JMenuItem("Quitter");
    protected JMenu jm_Fichier=new JMenu("Fichier");
    protected JMenuBar jmb_TheSurvivorWindowsBar=new JMenuBar();

    protected JPanel jp_mainPanel=new JPanel();
    protected JPanel jp_information=new JPanel();
    protected JPanel jp_control=new JPanel();
    protected JPanel jp_island=new JPanel();
    
    protected JButton jb_haut=new JButton("Haut");
    protected JButton jb_bas=new JButton("Bas");
    protected JButton jb_gauche=new JButton("Gauche");
    protected JButton jb_droite=new JButton("Droite");

    protected JLabel jl_herosName=new JLabel("R = RIMBO");

    protected Toolkit toolkit;
    protected Dimension screenSize;

    private TheSurvivorConfiguration theSurvivorConfiguration;
    private int islandNbRows;
    private int islandNbColumns;
    private Zone[][] island;
    private Manager manager;

    TheSurvivorWindows(TheSurvivorConfiguration theSurvivorConfiguration, int islandNbRows, int islandNbColumns)
    {
	int i,j;

	this.islandNbRows=islandNbRows;
	this.islandNbColumns=islandNbColumns;
	this.theSurvivorConfiguration=theSurvivorConfiguration;

	setTitle("TheSurvivor game");

	jmi_NouvellePartie.addActionListener(new ActionListener() 
	    {
		public void actionPerformed(ActionEvent ev)
		{
		    setVisible(false);
		    TheSurvivorWindows.this.theSurvivorConfiguration.reactivate();
		}
	    });

	jm_Fichier.add(jmi_NouvellePartie);
	jm_Fichier.add(jmi_Quitter);
	jmi_Quitter.addActionListener(new ExitAction());
	jmb_TheSurvivorWindowsBar.add(jm_Fichier);
	setJMenuBar(jmb_TheSurvivorWindowsBar);

	jp_information.add(jl_herosName);

	jp_island.setLayout(new GridLayout(this.islandNbRows,this.islandNbColumns));
	island=new Zone[this.islandNbRows][this.islandNbColumns];
	for(i=0;i<this.islandNbRows;i++)
	    {
		for(j=0;j<this.islandNbColumns;j++)
		    {
			Zone zone=new Zone();
			jp_island.add(zone);
			island[i][j]=zone; 
		    }
	    }

	

	jb_haut.setMnemonic(java.awt.event.KeyEvent.VK_UP);
	jb_bas.setMnemonic(java.awt.event.KeyEvent.VK_DOWN);
	jb_gauche.setMnemonic(java.awt.event.KeyEvent.VK_LEFT);
	jb_droite.setMnemonic(java.awt.event.KeyEvent.VK_RIGHT);

	jb_haut.addActionListener(new MoveAction("haut"));
	jb_gauche.addActionListener(new MoveAction("gauche"));
	jb_bas.addActionListener(new MoveAction("bas"));
	jb_droite.addActionListener(new MoveAction("droite"));
	
	jp_control.setLayout(new GridLayout(2,3));
	jp_control.add(new JLabel());
	jp_control.add(jb_haut);
	jp_control.add(new JLabel());
	jp_control.add(jb_gauche);
	jp_control.add(jb_bas);
	jp_control.add(jb_droite);


	jp_mainPanel.setLayout(new BorderLayout());
	jp_mainPanel.add(jp_information,BorderLayout.NORTH);
	jp_mainPanel.add(jp_island,BorderLayout.CENTER);
	jp_mainPanel.add(jp_control,BorderLayout.EAST);
	add(jp_mainPanel);

	setDefaultCloseOperation(EXIT_ON_CLOSE);

	setSize(WIDTH,HEIGHT);
	setResizable(false);
	toolkit=Toolkit.getDefaultToolkit();
	screenSize=toolkit.getScreenSize();
	setLocation((int)((screenSize.getWidth()/2)-getWidth()/2),(int)((screenSize.getHeight()/2)-getHeight()/2));


    }

    void init()
    {
	int i,j;
	
	for(i=0;i<this.island.length;i++)
	    {
		for(j=0;j<this.island[0].length;j++)
		    {
			this.island[i][j].init();
		    }
	    }

	if(manager==null)
	    {
		this.manager=new Manager(islandNbRows,islandNbColumns);
	    }
	else
	    {
		this.manager.init();
	    }
	askManager();
	setVisible(true);
    }
    
    private void askManager(){
    
    	Etat etat;
    	int i;
    	int j;
    		
	for(i=0;i<this.island.length;i++)
	    {
		for(j=0;j<this.island[0].length;j++)
		    {
			etat = this.manager.getPosition(i, j);
			
				if(etat == Etat.RIMBO){
					
					island[i][j].setBackground(Color.GRAY);
					island[i][j].setText("R");
				}
				else{
					if(etat == Etat.VISITEE){
					island[i][j].setText("");
					island[i][j].setBackground(Color.GRAY);
					}
					else{
					if(etat== Etat.NON_VISITEE){
					island[i][j].setText("J");
					island[i][j].setBackground(Color.WHITE);
					}
					}
				}
		}
					
	    }
    
    }
    
    class MoveAction implements ActionListener
    {
	private String direction;
	
	public MoveAction(String direction)
	{
	    this.direction=direction;
	
	}
	
	public void actionPerformed(ActionEvent ev)
	{
	    TheSurvivorWindows.this.manager.exploration(this.direction);
	    askManager();
	
	}
	
	public String toString()
	{
	    return "Pour aller vers le/la "+this.direction;
	}
    }
}
