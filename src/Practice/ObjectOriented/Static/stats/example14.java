package Practice.ObjectOriented.Static.stats;

class Student2{
    String name;
    int age;
    static String school = "A大学";
    public Student2(String name ,int age)
    {
        this.name=name;
        this.age=age;
    }
    public void info(){
        System.out.println(this.name +" "+ this.age +" "+school);
    }
}
public class example14 {
    public static void main(String[] args) {
        Student2 stu1 = new Student2("张三",18);
        Student2 stu2 = new Student2("李四",19);
        Student2 stu3 = new Student2("王五",20);
        stu1.info();
        stu2.info();
        stu3.info();
        stu1.school="B大学";
        stu1.info();
        stu2.info();
        stu3.info();
    }
}
