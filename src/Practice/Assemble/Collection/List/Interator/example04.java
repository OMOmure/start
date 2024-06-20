package Practice.Assemble.Collection.List.Interator;

import java.util.ArrayList;
import java.util.Iterator;
//迭代器Interator
public class example04 {
    public static void main(String[] args) {
        ArrayList list = new ArrayList();
        list.add("Omori");
        list.add("Aubrey");
        list.add("Kel");
        list.add("Hero");
        Iterator it = list.iterator();
        while (it.hasNext()){
            Object obj=it.next();
            if (obj=="Kel"){         //if("Kel".equals(obj))
                list.remove(obj);
                break;
            }
        }
        System.out.println(list);
    }
}
