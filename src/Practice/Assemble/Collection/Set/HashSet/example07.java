package Practice.Assemble.Collection.Set.HashSet;

import java.util.HashSet;
import java.util.Iterator;
//hashset散列表 由于根据特殊运算计算出散列值给元素定存储位置
//虽然可以省去重复数据 但不能有序
public class example07 {
    public static void main(String[] args) {
        HashSet set = new HashSet();
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
