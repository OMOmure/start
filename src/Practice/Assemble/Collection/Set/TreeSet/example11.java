package Practice.Assemble.Collection.Set.TreeSet;

import java.util.TreeSet;

// 因为hashset的无序且不重复，treeset应运而生
public class example11 {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet();
        ts.add(3);
        ts.add(1);
        ts.add(1);
        ts.add(2);
        ts.add(3);
        System.out.println(ts);
    }
}
