package Homework.StringOfAPI;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class CharacterFrequencyCounter {
    public static void main(String[] args) {
        String inputString = "uwd3j456jks8sufdhnk"; // 输入的字符串

        // 统计小写字母和数字的出现频率
        List<CharacterFrequency> frequencies = new ArrayList<>();
        for (char c : inputString.toCharArray()) {
            if (Character.isLowerCase(c)) {
                char index = c;
                addOrUpdateFrequency(frequencies, index, 1);
            } else if (Character.isDigit(c)) {
                char index = (char) ('a' + 26 + (c - '0')); // 使用 'a' + 26 作为数字的基准索引
                addOrUpdateFrequency(frequencies, index, 1);
            }
        }

        // 根据频率（降序）和字符（升序）对CharacterFrequency对象进行排序
        Collections.sort(frequencies, new Comparator<CharacterFrequency>() {
            @Override
            public int compare(CharacterFrequency o1, CharacterFrequency o2) {
                if (o1.frequency != o2.frequency) {
                    return Integer.compare(o2.frequency, o1.frequency); // 频率降序
                } else {
                    char c1 = (o1.character >= 'a' && o1.character <= 'z') ? o1.character : (char) (o1.character - 26 - 'a' + '0');
                    char c2 = (o2.character >= 'a' && o2.character <= 'z') ? o2.character : (char) (o2.character - 26 - 'a' + '0');
                    return Character.compare(c1, c2); // 字符升序
                }
            }
        });

        // 输出排序后的字符及其频率
        for (CharacterFrequency cf : frequencies) {
            char outputChar = (cf.character >= 'a' && cf.character <= 'z') ? cf.character : (char) (cf.character - 26 - 'a' + '0');
            System.out.println(outputChar + ": " + cf.frequency);
        }
    }

    private static void addOrUpdateFrequency(List<CharacterFrequency> frequencies, char index, int increment) {
        for (CharacterFrequency cf : frequencies) {
            if (cf.character == index) {
                cf.frequency += increment;
                return;
            }
        }
        frequencies.add(new CharacterFrequency(index, increment));
    }

    // 辅助类，用于存储字符及其频率
    static class CharacterFrequency {
        char character; // 字符，为了排序方便，将数字也映射到字符范围内（'a' + 26 到 'a' + 35）
        int frequency; // 频率

        CharacterFrequency(char character, int frequency) {
            this.character = character;
            this.frequency = frequency;
        }
    }
}