package Practice.API.String;
//string 常见操作（教材p110）
public class Example01 {
    public static void main(String[] args) {
        String s="ababcdedcba";
        System.out.println("字符串长度"+s.length());
        System.out.println("字符串第一个字符"+s.charAt(0));
        System.out.println("字符c第一次出现位置"+s.indexOf('c'));
        System.out.println("字符c最后一次出现位置"+s.lastIndexOf('c'));
        System.out.println("字符ab第一次出现位置"+ s.indexOf("ba"));
        System.out.println("字符串ab最后一次出现位置"+s.lastIndexOf("ab"));
    }
}
