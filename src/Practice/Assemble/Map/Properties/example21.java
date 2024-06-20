package Practice.Assemble.Map.Properties;

import java.util.Enumeration;
import java.util.Properties;

public class example21 {
    public static void main(String[] args) {
        Properties p = new Properties();
        p.setProperty("Backgroup-color","red");
        p.setProperty("Font-size","14px");
        p.setProperty("Language","chinese");
        Enumeration names = p.propertyNames();
        while (names.hasMoreElements()) {
            String key=(String) names.nextElement();
            String value=p.getProperty(key);
            System.out.println(key+"="+value);
        }
    }
}
