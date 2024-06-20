package Practice.API.Random;

import java.util.Random;

public class example01 {

    public static void main(String[] args) {
        Random r1 = new Random(13);
        System.out.println("种子13:");
        for (int i = 0; i < 10; i++) {
            System.out.print(r1.nextInt(100)+",");
        }
        Random r2 = new Random();
        System.out.println('\n'+"随机种子:");
        for (int i = 0; i < 10; i++) {
            System.out.print(r2.nextInt(100)+",");
        }
    }
}
