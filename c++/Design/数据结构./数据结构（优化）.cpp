#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 创建一个新节点并初始化其值
Node* createNode(int val) {
    Node* newNode = new Node; // 分配内存
    newNode->data = val; // 初始化数据
    newNode->next = nullptr; // 初始化指针
    return newNode;
}

// 插入元素到链表
void insert(Node*& head, int val) {
    Node* newNode = createNode(val); // 使用 createNode 代替构造函数
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 从一行输入中插入多个元素到链表
void insertMultiple(Node*& head, const string& input) {
    stringstream ss(input);
    int val;
    while (ss >> val) {
        insert(head, val);
    }
}

// 打印链表
void print(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// 求两个链表的交集
Node* intersect(Node* a, Node* b) {
    Node* result = nullptr;
    Node** tail = &result;
    while (a && b) {
        if (a->data < b->data) {
            a = a->next;
        } else if (a->data > b->data) {
            b = b->next;
        } else {
            *tail = createNode(a->data); // 使用 createNode 代替构造函数
            tail = &((*tail)->next);
            a = a->next;
            b = b->next;
        }
    }
    return result;
}

// 求两个链表的并集
Node* unionSet(Node* a, Node* b) {
    Node* result = nullptr;
    Node** tail = &result;
    while (a || b) {
        if (!b || (a && a->data < b->data)) {
            *tail = createNode(a->data); // 使用 createNode 代替构造函数
            tail = &((*tail)->next);
            a = a->next;
        } else if (!a || a->data > b->data) {
            *tail = createNode(b->data); // 使用 createNode 代替构造函数
            tail = &((*tail)->next);
            b = b->next;
        } else {
            *tail = createNode(a->data); // 使用 createNode 代替构造函数
            tail = &((*tail)->next);
            a = a->next;
            b = b->next;
        }
    }
    return result;
}

// 求两个链表的差集
Node* difference(Node* a, Node* b) {
    Node* result = nullptr;
    Node** tail = &result;
    while (a && b) {
        if (a->data < b->data) {
            *tail = createNode(a->data); // 使用 createNode 代替构造函数
            tail = &((*tail)->next);
            a = a->next;
        } else if (a->data > b->data) {
            b = b->next;
        } else {
            a = a->next;
            b = b->next;
        }
    }
    while (a) {
        *tail = createNode(a->data); // 使用 createNode 代替构造函数
        tail = &((*tail)->next);
        a = a->next;
    }
    return result;
}

// 求两个链表的对称差
Node* symmetricDifference(Node* a, Node* b) {
    Node* diff1 = difference(a, b);
    Node* diff2 = difference(b, a);
    Node* result = unionSet(diff1, diff2);
    return result;
}

// 清除屏幕内容
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    // POSIX系统 (Linux, macOS, etc.)
    cout << "\033[2J\033[1;1H";
#endif
}

void displayMenu() {
    cout << "+--------------------------------------+" << endl;
    cout << "|               菜单                   |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "| 1. 向集合A插入元素                  |" << endl;
    cout << "| 2. 向集合B插入元素                  |" << endl;
    cout << "| 3. 显示集合A                        |" << endl;
    cout << "| 4. 显示集合B                        |" << endl;
    cout << "| 5. 求A和B的交集                     |" << endl;
    cout << "| 6. 求A和B的并集                     |" << endl;
    cout << "| 7. 求A-B的差集                      |" << endl;
    cout << "| 8. 求对称差 (A - B) U (B - A)       |" << endl;
    cout << "| 9. 退出                             |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "请输入你的选择: ";
}

void printResultHeader(const string& operation) {
    cout << "+--------------------------------------+" << endl;
    cout << "|            " << operation << "            |" << endl;
    cout << "+--------------------------------------+" << endl;
}

int main() {
    Node* setA = nullptr;
    Node* setB = nullptr;
    int choice;
    string input;

    while (true) {
        clearScreen();
        displayMenu();
        cin >> choice;
        cin.ignore();  // 忽略换行符，以便getline正确读取
        clearScreen();
        switch (choice) {
            case 1:
                cout << "请输入要插入集合A的元素 (多个元素用空格隔开): ";
                getline(cin, input);
                insertMultiple(setA, input);
                break;
            case 2:
                cout << "请输入要插入集合B的元素 (多个元素用空格隔开): ";
                getline(cin, input);
                insertMultiple(setB, input);
                break;
            case 3:
                printResultHeader("集合A");
                print(setA);
                break;
            case 4:
                printResultHeader("集合B");
                print(setB);
                break;
            case 5: {
                printResultHeader("A和B的交集");
                Node* intersectSet = intersect(setA, setB);
                print(intersectSet);
                break;
            }
            case 6: {
                printResultHeader("A和B的并集");
                Node* unionResult = unionSet(setA, setB);
                print(unionResult);
                break;
            }
            case 7: {
                printResultHeader("A-B的差集");
                Node* diffSet = difference(setA, setB);
                print(diffSet);
                break;
            }
            case 8: {
                printResultHeader("对称差 (A - B) U (B - A)");
                Node* symDiffSet = symmetricDifference(setA, setB);
                print(symDiffSet);
                break;
            }
            case 9:
                cout << "退出..." << endl;
                return 0;
            default:
                cout << "无效选择，请重新输入。" << endl;
        }
        cout << "按回车键返回菜单...";
        cin.ignore();
        cin.get();
    }
}
