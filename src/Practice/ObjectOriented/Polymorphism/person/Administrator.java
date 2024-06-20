package Practice.ObjectOriented.Polymorphism.person;

public class Administrator extends Person{

    public void show() {
        System.out.println("管理员的信息为：" + getName() + "," + getAge());
    }
}
