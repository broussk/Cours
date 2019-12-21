/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Launcher_Example.Game.FindMe;

/**
 *
 * @author JC
 */
public class Manager implements java.io.Serializable{
    private boolean[][] clickedZone;
    private int line, column;
    private int remainingTries;
    private static final int NB_TRIES = 5;
    public Manager() {
        restart();   
    }   
    
    public boolean isHere(int i, int j)
    {   
        clickedZone[i][j]=true;
        remainingTries--;
        return i==line && j==column;
    }
    
    public int getRemainingTries()
    {
        return remainingTries;
    }
    
    public boolean isClicked(int i, int j)
    {
        return clickedZone[i][j];
    }
    
    public final void restart()
    {
        remainingTries = NB_TRIES;
        
        clickedZone=new boolean[4][4];
        
        line = (int)(Math.random()*4);
        column = (int)(Math.random()*4);
    }
   
}
