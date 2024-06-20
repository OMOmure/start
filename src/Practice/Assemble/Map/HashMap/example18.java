package Practice.Assemble.Map.HashMap;
//LinkedHashMap内部双向链表助于维护map元素迭代顺序一致
import java.util.*;
public class example18 {
    public static void main(String[] args) {
        LinkedHashMap map = new LinkedHashMap();
        map.put("1", "张三");
        map.put("2", "李四");
        map.put("3", "王五");
        Set keySet = map.keySet();          //entryset
        Iterator it = keySet.iterator();
        while (it.hasNext()) {
            Object key = it.next();
            Object value = map.get(key);
            System.out.println(key + ":" + value);
        }
    }
}