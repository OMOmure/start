package Homework.MallSystem;
import java.io.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class FileUtil {
    public static final String SEPARATE_FIELD = ","; // 字段分隔符
    public static final String SEPARATE_LINE = "\r\n"; // 行分隔符

    public static void saveGoods(Goods good) {
        Date date = new Date();
        DateFormat format = new SimpleDateFormat("yyyyMMdd");
        String name = "进货记录" + format.format(date) + ".csv";
        InputStream in = null;
        try {
            in = new FileInputStream(name);
            if (in != null) {
                in.close();
                createFile(name, true, good);
            }
        } catch (FileNotFoundException e) {
            createFile(name, false, good);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void createFile(String name, boolean label, Goods good) {
        BufferedOutputStream out = null;
        StringBuffer sbf = new StringBuffer();
        try {
            if (label) {
                out = new BufferedOutputStream(new FileOutputStream(name, true));
            } else {
                out = new BufferedOutputStream(new FileOutputStream(name));
                String[] fieldSort = new String[]{"商品编号", "商品名称", "购买数量", "单价", "总价", "联系人"};
                for (String fieldKey : fieldSort) {
                    sbf.append(fieldKey).append(SEPARATE_FIELD);
                }
                sbf.append(SEPARATE_LINE);
            }
            sbf.append(good.id).append(SEPARATE_FIELD);
            sbf.append(good.name).append(SEPARATE_FIELD);
            sbf.append(good.number).append(SEPARATE_FIELD);
            sbf.append(good.price).append(SEPARATE_FIELD);
            sbf.append(good.money).append(SEPARATE_FIELD);
            sbf.append(good.people).append(SEPARATE_FIELD);
            sbf.append(SEPARATE_LINE);

            byte[] b = sbf.toString().getBytes();
            for (byte aB : b) {
                out.write(aB);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (out != null) out.close();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    }

    public static void loadGoods(ArrayList<Goods> goodsList, String filename) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        String line;
        while ((line = reader.readLine()) != null) {
            if (line.trim().isEmpty()) continue;
            String[] parts = line.split(SEPARATE_FIELD);
            if (parts.length == 6) {
                int id = Integer.parseInt(parts[0]);
                String name = parts[1];
                double price = Double.parseDouble(parts[2]);
                int number = Integer.parseInt(parts[3]);
                double money = Double.parseDouble(parts[4]);
                String people = parts[5];
                goodsList.add(new Goods(id, name, price, number, money, people));
            }
        }
        reader.close();
    }

    public static void saveGoodsList(ArrayList<Goods> goodsList, String filename) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
        for (Goods good : goodsList) {
            writer.write(good.id + SEPARATE_FIELD +
                    good.name + SEPARATE_FIELD +
                    good.price + SEPARATE_FIELD +
                    good.number + SEPARATE_FIELD +
                    good.money + SEPARATE_FIELD +
                    good.people + SEPARATE_LINE);
        }
        writer.close();
    }
}
