package Practice.ObjectOriented.Polymorphism.person;

public class Test {
    public static void main(String[] args) {

        Student s = new Student();
        s.setName("张三");
        s.setAge(18);

        Teacher t = new Teacher();
        t.setName("王建国");
        t.setAge(30);

        Administrator admin = new Administrator();
        admin.setName("管理员");
        admin.setAge(35);

        regitser(s);
        regitser(t);
        regitser(admin);

    }

    //这个方法可以接受三家，
    //把参数写成这三个的父类
    public static void regitser(Person p) {
        p.show();
    }
}