package Practice.ObjectOriented.Extend.Extends;

class Animal{
    String name = "牧羊犬";
    void shout(){
        System.out.println("动物发出叫声");
    }
}

class Dog extends Animal{
    String name = "边境牧羊犬";
    public void shout(){
        super.shout();
        System.out.println("汪汪汪...");
    }
    public void printName(){
        System.out.println("名字"+super.name);
        System.out.println("名字"+name);
    }

}

public class example05 {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.shout();
        dog.printName();
        System.out.println("名字"+dog.name);
    }
}