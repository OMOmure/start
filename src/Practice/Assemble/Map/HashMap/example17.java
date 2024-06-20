package Practice.Assemble.Map.HashMap;
import java.util.*;

//扩展：map中操作集合的方法
public class example17 {
    public static void main(String[] args) {
        HashMap map = new HashMap();
        map.put("1","张三");
        map.put("3","李四");
        map.put("2","王五");
        map.put("4","赵六");
        System.out.println("集合大小为:"+map.size());
        System.out.println("判断是否包含传入的键:"+map.containsKey("2"));
        System.out.println("判断是否包含传入的值:"+map.containsValue("王五"));
        System.out.println("删除键为1的值是:"+map.remove("1"));
        Collection values = map.values();
        Iterator it = values.iterator();
        while (it.hasNext()) {
            Object value = it.next();
            System.out.println(value);
        }
    }
}
