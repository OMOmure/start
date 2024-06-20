package Homework.ScorePrinting;

import java.util.Arrays;
import java.util.List;

public class Student {
    private String studentId;
    private String name;
    private int chineseScore;
    private int mathScore;
    private int englishScore;

    // 构造方法
    public Student(String studentId, String name, int chineseScore, int mathScore, int englishScore) {
        this.studentId = studentId;
        this.name = name;
        this.chineseScore = chineseScore;
        this.mathScore = mathScore;
        this.englishScore = englishScore;
    }

    // 新增方法：计算平均分
    public double calculateAverageScore() {
        return (chineseScore + mathScore + englishScore) / 3.0;
    }

    // toString方法，添加了平均分的显示
    @Override
    public String toString() {
        double averageScore = calculateAverageScore();
        return String.format("%-10s %-10s %-10d %-10d %-10d %-10.2f", studentId, name, chineseScore, mathScore, englishScore, averageScore);
    }

    // 主函数，用于测试Student类
    public static void main(String[] args) {
        // 创建学生列表
        List<Student> students = Arrays.asList(
                new Student("001", "张三", 85, 90, 88),
                new Student("002", "李四", 80, 85, 92),
                new Student("003", "王五", 92, 88, 86),
                new Student("004", "赵六", 78, 90, 80)
        );

        // 打印表头，添加了平均分的表头
        System.out.println(String.format("%-10s %-10s %-10s %-10s %-10s %-10s", "学号", "姓名", "语文", "数学", "英语", "平均分"));

        // 遍历学生列表并打印每个学生信息及平均分
        for (Student student : students) {
            System.out.println(student);
        }
    }
}
