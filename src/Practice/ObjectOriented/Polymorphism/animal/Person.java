package Practice.ObjectOriented.Polymorphism.animal;

public class Person {

    private String name;
    private int age;

    public Person() {
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
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

    public void keepPet(Dog dog , String something){
        System.out.println("年龄为" + age +"岁的" + name + "养了一只" + dog.getColor() + "颜色的" + dog.getAge() + "的狗");
        dog.eat(something);
    }

    public void keepPet(Cat cat , String something){
        System.out.println("年龄为" + age +"岁的" + name + "养了一只" + cat.getColor() + "颜色的" + cat.getAge() + "的猫");
        cat.eat(something);
    }
}
