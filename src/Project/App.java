package Project;
import Project.puzzlegame.UI.GameJFrame;
import Project.puzzlegame.UI.LoginJFrame;
import Project.puzzlegame.UI.RegisterJFrame;

public class App {

    public static void main(String[] args) {
        //程序的启动入口
        new LoginJFrame();
        new GameJFrame();
        new RegisterJFrame();
    }
}
