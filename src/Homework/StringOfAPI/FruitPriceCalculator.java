package Homework.StringOfAPI;

public class FruitPriceCalculator {
    public static void main(String[] args) {
        // 电子秤反馈信息字符串
        String feedback = ".weight=32.145kg.weight=32.145kg.weight=32.145kg...";
        // 水果每公斤的价格
        double pricePerKg = 13.00;
        // 总重量初始化
        double totalWeight = 0;

        // 用于匹配字符串的前缀和后缀
        String prefix = "weight=";
        String suffix = "kg";
        // 查找前缀"weight="首次出现的位置
        int prefixIndex = feedback.indexOf(prefix);

        // 循环查找并解析所有的重量信息
        while (prefixIndex != -1) {
            // 找到重量值的起始位置，即前缀之后的位置
            int weightStartIndex = prefixIndex + prefix.length();

            // 从起始位置开始，查找后缀"kg"的位置，以确定重量值的结束位置
            int weightEndIndex = feedback.indexOf(suffix, weightStartIndex);

            // 如果没有找到后缀"kg"，则退出循环
            if (weightEndIndex == -1) {
                break;
            }

            // 截取重量值的字符串
            String weightStr = feedback.substring(weightStartIndex, weightEndIndex);

            // 将重量字符串转换为double类型的数值
            double weight = Double.parseDouble(weightStr);

            // 将解析出来的重量累加到总重量上
            totalWeight += weight;

            // 继续查找下一个前缀"weight="出现的位置，从而找到下一个重量值
            prefixIndex = feedback.indexOf(prefix, weightEndIndex + suffix.length());
        }

        // 根据总重量和单价计算总价
        double totalPrice = totalWeight * pricePerKg;
        // 打印出水果的总价
        System.out.println("水果的总价为: " + totalPrice + " 元");
    }
}