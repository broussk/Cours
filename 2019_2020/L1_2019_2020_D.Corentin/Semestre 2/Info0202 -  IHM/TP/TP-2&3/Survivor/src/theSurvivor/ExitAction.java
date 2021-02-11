package theSurvivor;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class ExitAction implements ActionListener
{
    public void actionPerformed(ActionEvent ev)
    {
	System.exit(0);
    }
}

class Coucou implements ActionListener
{
    public void actionPerformed(ActionEvent ev)
    {
	System.out.println("Coucou");
    }
}
