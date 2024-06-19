#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 插入元素到链表
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
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
            *tail = new Node(a->data);
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
            *tail = new Node(a->data);
            tail = &((*tail)->next);
            a = a->next;
        } else if (!a || a->data > b->data) {
            *tail = new Node(b->data);
            tail = &((*tail)->next);
            b = b->next;
        } else {
            *tail = new Node(a->data);
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
            *tail = new Node(a->data);
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
        *tail = new Node(a->data);
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

void displayMenu() {
    cout << "菜单:" << endl;
    cout << "1. 向集合A插入元素" << endl;
    cout << "2. 向集合B插入元素" << endl;
    cout << "3. 显示集合A" << endl;
    cout << "4. 显示集合B" << endl;
    cout << "5. 求A和B的交集" << endl;
    cout << "6. 求A和B的并集" << endl;
    cout << "7. 求A-B的差集" << endl;
    cout << "8. 求对称差 (A - B) U (B - A)" << endl;
    cout << "9. 退出" << endl;
    cout << "请输入你的选择: ";
}

int main() {
    Node* setA = nullptr;
    Node* setB = nullptr;
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "请输入要插入集合A的元素: ";
                cin >> value;
                insert(setA, value);
                break;
            case 2:
                cout << "请输入要插入集合B的元素: ";
                cin >> value;
                insert(setB, value);
                break;
            case 3:
                cout << "集合A: ";
                print(setA);
                break;
            case 4:
                cout << "集合B: ";
                print(setB);
                break;
            case 5: {
                Node* intersectSet = intersect(setA, setB);
                cout << "A和B的交集: ";
                print(intersectSet);
                break;
            }
            case 6: {
                Node* unionResult = unionSet(setA, setB);
                cout << "A和B的并集: ";
                print(unionResult);
                break;
            }
            case 7: {
                Node* diffSet = difference(setA, setB);
                cout << "A-B的差集: ";
                print(diffSet);
                break;
            }
            case 8: {
                Node* symDiffSet = symmetricDifference(setA, setB);
                cout << "对称差 (A - B) U (B - A): ";
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
