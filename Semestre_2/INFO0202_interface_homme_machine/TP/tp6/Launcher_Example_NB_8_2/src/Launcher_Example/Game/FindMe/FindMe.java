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
public class FindMe {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        javax.swing.JFrame jFrame = new javax.swing.JFrame("A game");
        
        jFrame.setDefaultCloseOperation(javax.swing.JFrame.EXIT_ON_CLOSE);
        jFrame.setSize(500, 500);
        jFrame.setResizable(false);
        jFrame.setLocationRelativeTo(null);
        
        FindMeGame game = new FindMeGame(jFrame.getContentPane());
        
        jFrame.setVisible(true);
    }
    
}
