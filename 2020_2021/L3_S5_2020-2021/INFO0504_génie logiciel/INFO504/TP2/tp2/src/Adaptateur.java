import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.*;

import javax.imageio.ImageIO;
import javax.imageio.stream.FileCacheImageInputStream;
import javax.swing.ImageIcon;

public class Adaptateur {
    public String encodeImage(String image) {
        File imageFile = new File(image);
        String s = "";
        ImageIcon img = new ImageIcon(image);
        System.out.println(img.toString());
        System.out.println(img.getIconHeight() + "px height");
        System.out.println(img.getIconWidth() + "px width");

        try {
            FileInputStream imageFileInputStream = new FileInputStream(imageFile);
            byte byteArray[] = new byte[(int) imageFile.length()];
            imageFileInputStream.read(byteArray);
            s = imageFileInputStream.toString();
        } catch (FileNotFoundException e) {
            System.out.println("erreur encodeImage dans Adaptateur : file not found \n " + e.toString());
        } catch (IOException e) {
            System.out.println("erreur encodeImage dans Adaptateur : io exception \n " + e.toString());
        }
        return s;
    }

    /*
    public boolean decodeImage(String imgageString){
        return false;
    }
    */
}