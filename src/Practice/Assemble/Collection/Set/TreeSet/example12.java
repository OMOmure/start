package Practice.Assemble.Collection.Set.TreeSet;
import java.util.TreeSet;

class Student implements Comparable<Student>{
    private String id;
    private String name;
    public Student(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String toString() {
        return id + ":" + name;
    }

    public int compareTo(Student o) {
        //return 0;
        //return 1;
        return -1;
    }

}


public class example12 {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet();
        ts.add(new Student("1","张三"));
        ts.add(new Student("2","李四"));
        ts.add(new Student("3","王五"));
        System.out.println(ts);
    }
}