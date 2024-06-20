package Homework.MallSystem;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class GoodOrder {
    static ArrayList<Goods> goodsList = new ArrayList<Goods>();
    static final String GOODS_FILE = "/Users/omori/Downloads/Code/IdeaProjects/IDEA-workspace/src/Homework/MallSystem/goods_info.csv";

    public static void main(String[] args) {
        try {
            FileUtil.loadGoods(goodsList, GOODS_FILE);
        } catch (IOException e) {
            System.out.println("初始化商品信息失败: " + e.getMessage());
        }

        for (Goods good : goodsList) {
            System.out.println(good);
        }

        Scanner scan = new Scanner(System.in);
        while (true) {
            System.out.println("请输入商品编号");
            int goodId = scan.nextInt();
            Goods stockGood = getGoodsById(goodId);
            if (stockGood != null) {
                System.out.println("当前商品库存信息: " + stockGood);
                System.out.print("请输入进货数量：");
                int goodNumber = scan.nextInt();
                stockGood.addNumber(goodNumber);  // 更新库存数量
                Goods newGood = new Goods(stockGood.id, stockGood.name, stockGood.price, stockGood.number, stockGood.price * stockGood.number, stockGood.people);
                FileUtil.saveGoods(newGood);
            } else {
                System.out.println("商品编号输入错误！");
            }
            System.out.println("是否继续操作? (yes/no)");
            String answer = scan.next();
            if (!answer.equalsIgnoreCase("yes")) {
                break;
            }
        }

        try {
            FileUtil.saveGoodsList(goodsList, GOODS_FILE);
        } catch (IOException e) {
            System.out.println("保存商品信息失败: " + e.getMessage());
        }
    }

    private static Goods getGoodsById(int goodId) {
        for (Goods good : goodsList) {
            if (good.id == goodId) {
                return good;
            }
        }
        return null;
    }
}
