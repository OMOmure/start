package Practice.ObjectOriented.Object;
class Animal{
    void shout(){
        System.out.println("动物叫");
    }
}
public class exampleno {
    public static void main(String[] args) {
        Animal animal = new Animal();
        System.out.println(animal.toString());
    }
}
