package Practice.ObjectOriented.Extend.Final;
class Animal2{
    public final void shout(){
    }
}
//继承
class Cat extends Animal2{
    //重写
    //public final void shout(){
   // }
}

public class example08 {
    public static void main(String[] args) {
        Cat cat = new Cat();
    }
}
