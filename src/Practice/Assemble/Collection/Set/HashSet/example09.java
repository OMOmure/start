package Practice.Assemble.Collection.Set.HashSet;
import java.util.HashSet;
//自定义类，hashset怎么计算散列值呢？
//必须要重写
class Student {
    String id;
    String name;
    public Student(String id, String name) {
        this.id = id;
        this.name = name;
    }
    //重写tostring方法
    public String toString() {
        return id + ":" + name;
    }
    //重写hashcode方法
    public int hashCode() {                 //签名不带参，自己加了java默认是新函数
        return id.hashCode();               //返回id值熟悉
    }
    //重写equals方法
    public boolean equals(Object obj) {
        if(this == obj){                    //判断是否是同一个对象
            return true;
        }
        if (!(obj instanceof Student)) {    //判断是否为学生对象
            return false;
        }
        Student stu = (Student)obj;
        boolean b = this.id.equals(stu.id);
        return b;
    }
}


public class example09 {
    public static void main(String[] args) {
        HashSet hs=new HashSet();
        Student stu1= new Student("1","张三");
        Student stu2= new Student("2","李四");
        Student stu3= new Student("2","李四");
        Student stu4= new Student("2","李为");
        hs.add(stu1);
        hs.add(stu2);
        hs.add(stu3);
        hs.add(stu4);
        System.out.println(hs);
    }
}
/*重写hashCode()方法时，应该保持方法签名的一致性，并确保使用适当的属性来计算哈希码，
以便在集合类中正确地管理和检索对象。这样可以确保集合类在处理对象时能够高效且正确地工作。
为什么不一致它不报错，还让我运行，并且函数失效了
ChatGPT
Java编译器不会直接报错，因为在Java中，方法的签名（即方法名称、参数类型和顺序）决定了方法的唯一性，而不仅仅是方法名称。
因此，如果你定义了一个方法，它与父类中的方法具有不同的签名，编译器会将它视为一个新的方法，而不是重写父类中的方法。
*/