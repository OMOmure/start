package Homework.MallSystem;

public class Goods {

        int id;
        String name;     // 商品名称
        double price;    // 商品单价
        int number;      // 商品库存数量
        double money;    // 商品总价
        String people;   // 联系人

        public Goods(int id, String name, double price, int number, double money, String people) {
            this.id = id;
            this.name = name;
            this.price = price;
            this.number = number;
            this.money = money;
            this.people = people;
        }

        @Override
        public String toString() {
            return "进货记录编号：" + id + "\n商品名称：" + name + "\n联系人：" + people + "\n单价：" + price + "\n库存数量：" + number + "\n";
        }

        public void setNumber(int number) {
            this.number = number;
        }

        public void addNumber(int number) {
            this.number += number;
        }
    }

