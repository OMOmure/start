package Practice.Assemble.Map.TreeMap;
import java.util.*;
class Student {
    private String name;
    private int age;
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
    public Student(String name, int age) {
        super();
        this.name = name;
        this.age = age;
    }
    public String toString() {
        return "Student [name=" + name + ", age=" +age+ "]";
    }
}

public class example20 {
    public static void main(String[] args) {
        TreeMap tm = new TreeMap(new Comparator<Student>(){
            @Override
            public int compare(Student s1,Student s2) {
                int flag=s1.getAge()-s2.getAge();
                return flag == 0?s1.getName().compareTo(s2.getName()):flag;
            }
        });
        tm.put(new Student("张三",23),"北京");
        tm.put(new Student("李四",13),"上海");
        tm.put(new Student("赵六",43),"广州");
        tm.put(new Student("王五",33),"深圳");
        Set keySet = tm.keySet();
        Iterator it = keySet.iterator();
        while (it.hasNext()) {
            Object key = it.next();
            Object value = tm.get(key);
            System.out.println(key+":"+value);
        }
    }
}