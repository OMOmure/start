package Practice.ObjectOriented.Object;

class Person{
    void yell(){
        System.out.println("啊啊啊");
    }

    @Override
    public String toString() {
        return "这是一个人";
    }
}
public class exampleyes {
    public static void main(String[] args) {
        Person person = new Person();
        System.out.println(person.toString());
    }
}
