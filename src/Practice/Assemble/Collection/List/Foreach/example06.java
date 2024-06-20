package Practice.Assemble.Collection.List.Foreach;
//foreach循环简洁，但是只能创建临时变量，不能修改数据
public class example06 {
    static String[] strs= {"aaa","bbb","ccc"};
    public static void main(String[] args) {
        for(String str:strs){
            str="ddd";
        }
        System.out.println("foreach循环的:"+strs[0]+strs[1]+strs[2]);
        for (int i = 0; i < strs.length; i++) {
            strs[i]="ddd";
        }
        System.out.println("for循环的:"+strs[0]+strs[1]+strs[2]);
    }
}