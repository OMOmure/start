package Practice.Assemble.Collection.Set.HashSet;

import java.util.Iterator;
import java.util.LinkedHashSet;
//LinkedHashSet内部有双向链表维护内部元素有序
public class example10 {
    public static void main(String[] args) {
        LinkedHashSet set = new LinkedHashSet();            //LinkedHashSet内部有双向链表维护内部元素有序
        set.add("张三");
        set.add("李四");
        set.add("王五");
        Iterator it = set.iterator();
        while (it.hasNext()) {
            Object obj = it.next();
            System.out.println(obj);
        }
    }
}
