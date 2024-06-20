package Practice.API.String;

public class StringBuffer {
    public static void main(String[] args) {
        System.out.println("添加——————————————");
        add();
        System.out.println("删除——————————————");
        remove();
        System.out.println("修改——————————————");
        alter();
    }
    public static void add() {
        StringBuilder sb =new StringBuilder();
        sb.append("abcdefg");
        System.out.println("添加结果："+sb);
        sb.insert(2,123);
        System.out.println("插入结果:"+sb);
    }

    public static void remove() {
        StringBuilder sb = new StringBuilder("abcdefg");
        sb.delete(1,2);
        System.out.println("删除指定范围:"+sb);
        sb.deleteCharAt(0);
        System.out.println("删除指定位置:"+sb);
        sb.delete(0,sb.length());
        System.out.println("清空缓存区:"+sb);
    }
    private static void alter() {
    StringBuilder sb = new StringBuilder("abcdefg");
    sb.setCharAt(0,'改');
    System.out.println("修改指定位置字符结果:"+sb);
    sb.replace(1,3,"q");
    System.out.println("替换指定范围字符串:"+sb);
    System.out.println("字符串反转结果:"+sb.reverse());
    }
}
