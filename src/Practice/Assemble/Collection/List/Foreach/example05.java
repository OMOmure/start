package Practice.Assemble.Collection.List.Foreach;

import java.util.ArrayList;
//foreach循环简洁，但是只能创建临时变量，不能修改数据
public class example05 {
    public static void main(String[] args) {
        ArrayList list = new ArrayList();
        list.add("aaa");
        list.add("bbb");
        list.add("ccc");
        for(Object obj:list){
            System.out.println(obj);
        }

    }
}
