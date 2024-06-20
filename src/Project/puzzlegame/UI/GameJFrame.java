package Project.puzzlegame.UI;

import javax.swing.*;
import java.util.Random;
public class GameJFrame extends JFrame {

    //创建一个二维数组
    //目的：用来管理数据
    //加载图片的时候，会根据二维数组中的数据进行加载
    int[][] data = new int[4][4];

    public GameJFrame(){
        //初始化界面
        initFrame();
        //初始化菜单
        initJMenuBar();
        //初始化数据
        initData();
        //初始化图片
        initImage();
        //让显示显示出来，建议写在最后
        this.setVisible(true);
    }

    //初始化数据（打乱）
    private void initData() {
        //需求：
        //把一个一位数组中的数据：0～15打乱顺序
        //然后再按照4个一组的方式添加到二维数组中
        //1.定义一个一维数组
        int[] tempArr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        //2.打乱数组中的数据的顺序
        //遍历数组，得到每一个元素，拿着每一个元素跟随机索引上的数据进行交换
        Random r = new Random();
        for (int i = 0; i < tempArr.length; i++) {
            //获取随机索引
            int index = r.nextInt(tempArr.length);
            //拿着遍历到的每一个数据，跟随机索引上的数据进行交换
            int temp = tempArr[i];
            tempArr[i]=tempArr[index];
            tempArr[index]=temp;
        }
        System.out.print("\n");
        //5.给二维数组添加数据
        for (int i = 0; i < tempArr.length; i++) {
            data[i/4][i%4] = tempArr[i];
        }
    }

    //初始化图片
    //添加图片的时候，就需要按照二维数组中管理的数据进行添加图片
    private void initImage() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                //获取当前要加载图片的序号
                int number=data[i][j];
                //创建一个图片一个JLabel对象（管理容器）
                JLabel jLabel = new JLabel(new ImageIcon("/Users/omori/Downloads/Code/IdeaProjects/IDEA-workspace/素材/image/animal/animal3/"+number+".jpg"));
                //指定图片位置
                jLabel.setBounds(105*j,105*i,105,105);
                //把管理容器添加到界面中 this.add(jLabel);
                this.getContentPane().add(jLabel);
            }
        }


    }


    private void initJMenuBar() {
        //初始化菜单
        //创建整个菜单对象
        JMenuBar jMenuBar = new JMenuBar();

        //创建菜单上面的两个选项的对象（功能 关于我们）
        JMenu functionJMenu =new JMenu("功能");
        JMenu aboutJMenu = new JMenu("关于我们");

        //创建选项下面的条目对象
        JMenuItem replayItem = new JMenuItem("重新游戏");
        JMenuItem reLoginItem = new JMenuItem("重新登陆");
        JMenuItem closeItem = new JMenuItem("退出游戏");

        JMenuItem accountItem = new JMenuItem("公众号");

        //将每一个选项下的条目添加到选项当中
        functionJMenu.add(replayItem);
        functionJMenu.add(reLoginItem);
        functionJMenu.add(closeItem);

        aboutJMenu.add(accountItem);

        //将菜单里的两个选项添加到菜单中
        jMenuBar.add(functionJMenu);
        jMenuBar.add(aboutJMenu);

        //给整个界面设置菜单
        this.setJMenuBar(jMenuBar);
    }

    private void initFrame() {
        this.setSize(488,430);
        //设置界面标题
        this.setTitle("拼图单机版 v1.0");
        //设置界面置顶
        this.setAlwaysOnTop(true);
        //设置界面居中
        this.setLocationRelativeTo(null);
        //设置游戏关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        //取消默认居中放置，只有取消了才会按照XY轴的形式添加
        this.setLayout(null);

    }
}
