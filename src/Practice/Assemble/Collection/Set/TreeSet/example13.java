package Practice.Assemble.Collection.Set.TreeSet;
import java.util.Comparator;
import java.util.TreeSet;

class Student2{
    private String id;
    private String name;
    public Student2(String id, String name){
        this.id=id;
        this.name=name;
    }
    //重写方法
    public String toString(){
        return id+":"+name;
    }
}

public class example13 {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet(new Comparator(){
            @Override
            public int compare(Object o1, Object o2) {
                return -1;
            }
        });
        ts.add(new Student("1","张三"));
        ts.add(new Student("2","李四"));
        ts.add(new Student("2","李四"));
        System.out.println(ts);
    }
}
