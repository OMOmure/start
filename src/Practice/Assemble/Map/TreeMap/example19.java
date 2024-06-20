package Practice.Assemble.Map.TreeMap;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeMap;
public class example19 {
    public static void main(String[] args) {
        TreeMap map = new TreeMap();
        map.put(3,"李四");
        map.put(2,"王五");
        map.put(4,"赵六");
        map.put(3,"张三");
        Set keySet = map.keySet();
        Iterator it = keySet.iterator();
        while (it.hasNext()) {
        Object key = it.next();
        Object value = map.get(key);
        System.out.println(key+":"+value);
        }
    }
}
