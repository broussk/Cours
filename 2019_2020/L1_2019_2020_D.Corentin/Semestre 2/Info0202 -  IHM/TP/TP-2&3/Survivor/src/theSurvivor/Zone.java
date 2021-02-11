package theSurvivor;

import javax.swing.JButton;
import java.awt.Color;

class Zone extends JButton
{
  public Zone()
    {
	this.setBackground(Color.GRAY);
	this.setEnabled(false);
    }

    public String toString()
    {
	return "";
    }

    public void explore()
    {
	this.setBackground(Color.WHITE);
    }

    public void init()
    {
	this.setBackground(Color.GRAY);
    }
}
