package Practice.ObjectOriented.Extend.Extends;

class Animal2{
    private String name;
    private int age;
    public Animal2(String name,int age){
        this.name=name;
        this.age=age;
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

    public String info(){
        return this.getName()+this.getAge();
    }
}

class Cat extends Animal2{
    private String color;

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Cat(String name, int age,String color) {
        super(name, age);
        this.setColor(color);
    }

    @Override
    public String info() {
        return super.info()+this.color;
    }
}

public class example06 {
    public static void main(String[] args) {
        Cat cat = new Cat("美短",7, "灰色");
        System.out.println(cat.info());
    }
}
