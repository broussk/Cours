import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Graphics;
import java.awt.Color;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;



public class MyJLabel extends JLabel
{
	private static final long serialVersionUID = 111111111111L;
	
	public MyJLabel(int value)
	{
		this.setHorizontalAlignment(SwingConstants.CENTER);
		this.setVerticalAlignment(SwingConstants.CENTER);
		this.setText(Integer.toString(value));

		this.addMouseListener( new MouseListener() {
			/*public void mouseClicked(MouseEvent e)
			{
				if(e.getButton()==MouseEvent.BUTTON1)
				{
					String value= MyJLabel.this.getText();
					int intValue=Integer.parseInt(value);
					MyJLabel.this.setText(Integer.toString(intValue-1));
				}
			}*/
			public void mouseExited(MouseEvent e){System.out.println("Au revoir !");}
			public void mouseEntered(MouseEvent e){System.out.println("Bonjour c'est Mickey Mouse");}
			public void mouseReleased(MouseEvent e){System.out.println("Tu fais mal !!!");}
			public void mousePressed(MouseEvent e){System.out.println("Aie!!");}
			public void mouseClicked(MouseEvent e){System.out.println("Tu click sur moi !!");}
			public void mouseMoved(MouseEvent e){System.out.println("Tu bouges !");}
		});
	}			
				

	public void paintComponent(Graphics g)
	{
		int largeur=this.getWidth();
		int hauteur=this.getHeight();
  
		super.paintComponent(g);
		//oreilles
		g.setColor(Color.WHITE);
		g.drawOval(largeur/8,hauteur/8,largeur/4,hauteur/4);
		g.drawOval(largeur/2+largeur/8,hauteur/8,largeur/4,hauteur/4);
		g.setColor(Color.BLACK);
		g.fillOval(largeur/8,hauteur/8,largeur/4,hauteur/4);
		g.fillOval(largeur/2+largeur/8,hauteur/8,largeur/4,hauteur/4);
		g.setColor(new Color(20,20,20));//g.setColor(Color.GREEN);
		g.fillOval(largeur/8+largeur/32,hauteur/8+hauteur/32-hauteur/64+hauteur/64,largeur/5,hauteur/5);
		g.fillOval(largeur/2+largeur/8+largeur/32-largeur/64,hauteur/8+hauteur/32,largeur/5,hauteur/5);

		//tete	
			//visage
		g.setColor(new Color(255,197,168));
		g.fillOval(largeur/4,hauteur/4,largeur/2,hauteur/2);
			//contour
		g.setColor(Color.BLACK);
		g.drawOval(largeur/4,hauteur/4,largeur/2,hauteur/2);

		//yeux
			//blanc de l'oeil
		g.setColor(Color.WHITE);
		g.fillOval(largeur/8+largeur/4+largeur/8+largeur/18-largeur/48,hauteur/3,largeur/6,hauteur/4);
		g.fillOval(largeur/8+largeur/8+largeur/8-largeur/18,hauteur/3,largeur/6,hauteur/4);
			//iris
		g.setColor(Color.BLACK);
		g.fillOval(largeur/2+5*(largeur/64)+largeur/128,hauteur/2-hauteur/10,largeur/14,hauteur/9);
		//g.fillOval(largeur/2+largeur/64,hauteur/4+hauteur/8-hauteur/16,largeur/12,hauteur/8);
		g.fillOval(largeur/4+6*(largeur/64)+largeur/32,hauteur/2-hauteur/10,largeur/14,hauteur/9);
		//g.fillOval(largeur/4+largeur/16-largeur/128,hauteur/4+hauteur/8-hauteur/16,largeur/12,hauteur/8);
			//contours
		g.setColor(Color.BLACK);
		g.drawOval(largeur/8+largeur/4+largeur/8+largeur/18-largeur/48,hauteur/3,largeur/6,hauteur/4);
		g.drawOval(largeur/8+largeur/8+largeur/8-largeur/18,hauteur/3,largeur/6,hauteur/4);

		//sourire
		g.setColor(Color.BLACK);
		g.drawArc(largeur/2-largeur/16,hauteur/4+hauteur/4+hauteur/32,largeur/8,hauteur/8,0,-180);
		
	}
}
