package Practice.ObjectOriented.Class;

class Student{
    private String name;
    private int age;
    public Student(){
        System.out.println("实例化了一个新的Student对象");
    }
    public Student(String name,int age){
        this();
        this.name=name;
        this.age=age;
    }
    public String read(){
        return name+age;
    }
}
public class this关键字 {
    public static void main(String[] args) {
        Student stu = new Student("张三",18);
        System.out.println(stu.read());
    }
}
