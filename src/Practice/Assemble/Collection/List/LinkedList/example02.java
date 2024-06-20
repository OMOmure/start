package Practice.Assemble.Collection.List.LinkedList;

import java.util.*;
//链表增删效率高
public class example02 {
    public static void main(String[] args) {
        LinkedList link = new LinkedList();
        link.add("Omori");
        link.add("Aubrey");
        link.add("Kel");
        link.add("Hero");
        System.out.println(link);
        System.out.println(link.toString());
        link.add(1,"Basil");
        link.addFirst("Marry");
        System.out.println(link);
        System.out.println(link.getFirst());
        link.remove(1);
        link.removeFirst();
        System.out.println(link);
    }
}