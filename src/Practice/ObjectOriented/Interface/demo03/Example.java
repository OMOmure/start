package Practice.ObjectOriented.Interface.demo03;

interface Animal{
    public String NAME = "牧羊犬";
    public void shout();
    public void info();
}

abstract class Action{
    public abstract void eat();
}

class Dog extends Action implements Animal{
    @Override
    public void info() {
        System.out.println(NAME);
    }

    @Override
    public void shout() {
        System.out.println("汪汪");
    }

    @Override
    public void eat() {
        System.out.println("喜欢吃骨头");
    }
}
public class Example {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.info();
        dog.shout();
        dog.eat();
    }
}
