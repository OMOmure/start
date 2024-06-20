package Practice.Assemble.Map.HashMap;
//无重复键值且无序
public class example14 {
    public static void main(String[] args) {
        java.util.HashMap map = new java.util.HashMap();
        map.put("1","张三");
        map.put("2","李四");
        map.put("3","王五");
        System.out.println("1" + ":" + map.get("1"));
        System.out.println("2" + ":" + map.get("2"));
        System.out.println("3" + ":" + map.get("3"));
    }
}
