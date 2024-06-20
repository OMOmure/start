package Practice.ObjectOriented.Static.stats;

class Student{
    String name;
    int age;
    String school = "A大学";
    public Student(String name ,int age)
    {
        this.name=name;
        this.age=age;
    }
    public void info(){
        System.out.println(this.name +" "+ this.age +" "+school);
    }
}
public class emample13 {
    public static void main(String[] args) {
        Student stu1 = new Student("张三",18);
        Student stu2 = new Student("李四",19);
        Student stu3 = new Student("王五",20);
        stu1.info();
        stu2.info();
        stu3.info();
    }
}
