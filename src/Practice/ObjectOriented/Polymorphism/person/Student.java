package Practice.ObjectOriented.Polymorphism.person;

public class Student extends Person{

    public void show() {
        System.out.println("学生的信息为：" + getName() + "," + getAge());
    }
}
