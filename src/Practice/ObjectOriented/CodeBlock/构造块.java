package Practice.ObjectOriented.CodeBlock;

class Student{
        String name;
        {
            System.out.println("我是构造代码块");
        }
        //构造方法
        public Student(){
            System.out.println("我是Student 类的构造方法");
        }
    }
public class 构造块 {
    public static void main(String[] args) {
        //Student stu1 = new Student();会调用类里的内容
        Student stu1 = new Student();
        Student stu2 = new Student();
    }
}
