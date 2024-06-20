package Practice.ObjectOriented.Extend.Abstract;

abstract class Animal{
    abstract void shout();
}
class Cat extends Animal{
    void shout(){
        System.out.println("mmmm");
    }
}

public class example10 {
    public static void main(String[] args) {
        Cat cat = new Cat();
        cat.shout();
    }
}
