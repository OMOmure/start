package Practice.ObjectOriented.Static.block;

class Student{
    {
        System.out.println("我是构造代码块");
    }
    static {
        System.out.println("我是静态代码块");
    }
    public Student(){
        System.out.println("我是Student类的构造方法");
    }
}

public class example16 {
    public static void main(String[] args) {
        Student stu1 = new Student();
        Student stu2 = new Student();
        Student stu3 = new Student();
    }
}
