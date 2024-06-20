package Practice.ObjectOriented.Interface.demo02;

interface Animal{
    int ID = 1;
    String NAME = "牧羊犬";
    void shout();               //定义抽象方法shout()
    static int getID(){
        return Animal.ID;
    }
    public void info();         //定义抽象方法info()
}
interface Action{
    public void eat();          //定义抽象方法eat()
}
class Dog implements Animal,Action{
    public void eat(){                      //重写eat()
        System.out.println("喜欢吃骨头");
    }
    public  void shout(){                   //重写shout()
        System.out.println("汪汪");
    }
    public void info(){                     //重写info（）
        System.out.println("名称"+NAME);
    }
}

public class Example {
    public static void main(String[] args) {
        System.out.println("编号"+Animal.getID());
        Dog dog = new Dog();
        dog.info();
        dog.shout();
        dog.eat();
    }
}
