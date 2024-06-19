#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // 打开文件
    ifstream fin("/Users/omori/Downloads/graph_data.txt");
    if (!fin) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    // 逐行读取文件内容并输出
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }

    // 关闭文件
    fin.close();

    return 0;
}
