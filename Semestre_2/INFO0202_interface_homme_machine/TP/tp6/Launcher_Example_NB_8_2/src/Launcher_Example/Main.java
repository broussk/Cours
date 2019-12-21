package Launcher_Example;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
public class Main extends Application {


    @Override
    public void start(Stage primaryStage) throws Exception{
        
        FXMLLoader loader = new FXMLLoader(getClass().getResource("Launcher_01.fxml"));
        
        //Parent root = FXMLLoader.load(getClass().getResource("Launcher.fxml"));
        
        Parent root = (Parent)loader.load();
        
        Controller controller = (Controller)loader.getController();
        controller.setStage(primaryStage);
        
        primaryStage.setTitle("Standard launcher");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
