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
public class MyButton extends javax.swing.JButton{
    
      private final int line;
      private final int column;
      
      public MyButton(int line, int column)
      {
          this.line=line;
          this.column=column;
      }
      
      public int getLine()
      {
          return line;
      }
      
      public int getColumn()
      {
          return column;
      }

}
