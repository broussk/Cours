/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Launcher_Example.Game;

/**
 *
 * @author JC
 */
public abstract class Game
{
    protected enum State{INITIALIZED, STARTED, STOPPED, PAUSED}
    
    private final String name;
    protected State currentState;
            
    public Game(String name)
    {
        this.name=name;
        this.currentState=State.INITIALIZED;
    }
    
    /**
     *
     * @param file The file where the game as to be saved
     */
    public abstract void saveGame(java.io.File file);
    
     /**
     *
     * @param file The file from where the game as to be restored
     */
    public abstract void loadGame(java.io.File file);
        
    public abstract void startGame();
    
    public abstract void stopGame();
       
    public abstract void pauseGame();
    
    public String getName()
    {
        return this.name;
    }
    
}
