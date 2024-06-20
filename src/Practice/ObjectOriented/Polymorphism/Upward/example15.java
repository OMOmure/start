package Practice.ObjectOriented.Polymorphism.Upward;

class Animal{
    public void shout(){
        System.out.println("喵喵");
    }
}
class Dog extends Animal{
    public void shout(){
        System.out.println("汪汪");
    }
    public void eat(){
        System.out.println("吃骨头");
    }
}

public class example15 {
    public static void main(String[] args) {
        Dog dog = new Dog();
        Animal an = dog;
        an.shout();
        //an.eat();
    }
}
