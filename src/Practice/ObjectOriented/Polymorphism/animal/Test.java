package Practice.ObjectOriented.Polymorphism.animal;

public class Test {
    public static void main(String[] args) {
        Person p1 = new Person("老王",30);
        Dog d = new Dog(2,"黑");
        p1.keepPet(d,"骨头");

    }




}
