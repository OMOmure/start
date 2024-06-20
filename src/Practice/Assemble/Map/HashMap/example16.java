package Practice.Assemble.Map.HashMap;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
//用entryset获得键与值所有映射关系

public class example16 {
    public static void main(String[] args) {
        HashMap map = new HashMap();
        map.put("1","张三");
        map.put("2","李四");
        map.put("3","王五");
        Set entrySet = map.entrySet();          //entryset
        Iterator it = entrySet.iterator();
        while (it.hasNext()) {
            //获得所有键值关系
            Map.Entry entry = (Map.Entry)(it.next());
            Object key = entry.getKey();
            Object value= entry.getValue();
            System.out.println(key+" "+value);
        }
        }
}
