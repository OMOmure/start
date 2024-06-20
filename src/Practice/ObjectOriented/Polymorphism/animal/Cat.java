package Practice.ObjectOriented.Polymorphism.animal;

public class Cat extends Animal {

    public Cat() {
    }

    public Cat(int age, String color) {
        super(age, color);
    }

    public void eat(String something){
        System.out.println(getAge() + "岁的" + getColor() + "颜色的猫眯着眼睛侧着头吃" + something);
    }

    public void catMouse(){
        System.out.println("猫抓老鼠");
    }
}
