package Practice.ObjectOriented.Polymorphism.Downward;


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

public class emample16 {
    public static void main(String[] args) {
        Animal an = new Dog();
        Dog dog = (Dog) an;
        dog.shout();
        dog.eat();
    }
}
