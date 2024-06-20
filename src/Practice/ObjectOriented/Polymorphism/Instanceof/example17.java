package Practice.ObjectOriented.Polymorphism.Instanceof;

class Animal{
    public void shout(){
        System.out.println("动物叫");
    }
}
class Dog extends Animal{
    public void shout(){
        System.out.println("汪汪汪");
    }
    public void eat(){
        System.out.println("吃骨头");
    }
}
public class example17 {
    public static void main(String[] args) {
        Animal a1 = new Dog();
        System.out.println("Animal a1 = new Dog()："+ (a1 instanceof Animal));
        System.out.println("Animal a1 = new Dog()："+ (a1 instanceof Dog));
        Animal a2 = new Animal();
        System.out.println("Animal a2 = new Animal()："+ (a2 instanceof Animal));
        System.out.println("Animal a2 = new Animal()："+ (a2 instanceof Dog));
    }
}
