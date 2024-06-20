package Practice.ObjectOriented.Static.method;
class Student{
    private String name;
    private int age;
    private static String school="A大学";
    public Student(String name , int age){
        this.name=name;
        this.age=age;
    }
    public void info(){
        System.out.println(name + age + school);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static String getSchool() {
        return school;
    }

    public static void setSchool(String school) {
        Student.school = school;
    }
}

public class example15 {
    public static void main(String[] args) {
        Student stu1 = new Student("张三",18);
        Student stu2 = new Student("李四",19);
        Student stu3 = new Student("王五",20);
        stu1.info();
        stu2.info();
        stu3.info();
        stu1.setAge(20);
        stu1.setName("小明");
        stu1.setSchool("B大学");
        stu1.info();
        stu2.info();
        stu3.info();
    }
}
