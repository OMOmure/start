#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef char** HuffmanCode; // 动态分配数组存储哈夫曼编码
typedef struct {
    double weight; // 权重
    char s;
    int parent, lchild, rchild; // 双亲，左孩子和右孩子的下标
}HTNode, * HuffmanTree;

void shuchu(HuffmanTree HT, int n) { // 输出函数
    cout << "结点i  weight  parent  lchild  rchild " << endl;
    for (int i = 1; i <= n; i++)
        cout << i << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
}

void  Select(HuffmanTree &HT, int l, int &s1, int &s2) { // 选择最小的两个数
    double m = 999999;
    double n = 999999;
    int x;
    for (x = 1; x <= l; x++) {
        if (HT[x].parent == 0 && HT[x].weight < m) {
            m = HT[x].weight;
            s1 = x;
        }
    }
    for (int i = 1; i <= l; i++) {
        if (HT[i].parent == 0 && HT[i].weight < n && i != s1) {
            n = HT[i].weight;
            s2 = i;
        }
    }
}

void CreateHuffmanTree(HuffmanTree& HT, int n) {
    if (n <= 1) // 看长度对不对
        return;
    int m = 0;
    m = 2 * n - 1; // 长度
    HT = new HTNode[m + 1]; // 动态申请2n个空间
    for (int i = 1; i <= m; i++) // 从一开始将所有初始化为0
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    int weights[] = {5, 12, 6, 3, 1, 9, 13, 8}; // 初值的权值数组

    for (int i = 1; i <= n; i++) {
        HT[i].weight = weights[i-1]; // 赋值初值的权值
    }

    char s[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // 初值的字符数组
    for (int i = 1; i <= n; i++) {
        HT[i].s = s[i-1]; // 赋值初值的字符
    }

    cout << "初始状态为：" << endl;
    shuchu(HT, n);

    // 创建开始
    int s1, s2;
    s1 = s2 = 0;
    for (int i = n + 1; i <= m; i++) {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) { // 求编码
    char* cd;
    HC = new char* [n + 1];
    cd = new char[n];
    cd[n - 1] = '\0'; // 倒着找
    for (int i = 1; i <= n; ++i) {
        int start, c, f;
        start = n - 1;
        c = i;
        f = HT[i].parent;
        while (f != 0) {
            --start;
            if (HT[f].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
} 
int main() {
    HuffmanTree HT;
    int n = 8; // 初值节点个数
    int m = 15; // 最终状态节点个数

    CreateHuffmanTree(HT, n);
    cout << "最终状态为：" << endl;
    shuchu(HT, m);
    HuffmanCode HC;
    CreateHuffmanCode(HT, HC, n);
    for (int i = 1; i <= n; i++) { // 遍历输出编码
        cout << HT[i].s << "的哈夫曼编码为：" << HC[i];
        cout << endl;
    }
}