package Practice.Assemble.Map.HashMap;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
//用迭代器获取键值
public class example15 {
    public static void main(String[] args) {
        HashMap map = new java.util.HashMap();
        map.put("1","张三");
        map.put("2","李四");
        map.put("3","王五");
        Set keySet = map.keySet();          //键值的集合
        Iterator it = keySet.iterator();    //迭代器集合
        while (it.hasNext()) {
            Object key = it.next();
            Object value = map.get(key);    //获得每个件的值
            System.out.println(key+":"+value);
        }
    }
}
