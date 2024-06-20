#include <iostream>  
#include <string>  
#include <fstream>  
using namespace std;
const char* filename = "/Users/omori/Downloads/drugs.txt"; //文件地址
const int MAX_DRUGS = 100;
const int MAX_STRING_LENGTH = 100;
struct Drug {
    char id[MAX_STRING_LENGTH];                 //药品id
    char name[MAX_STRING_LENGTH];               //药品名称
    char effect[MAX_STRING_LENGTH];             //药品功效
    char manufacturerName[MAX_STRING_LENGTH];   // 制造商名称  
    char adminName[MAX_STRING_LENGTH];          // 管理员姓名  
    char productionDate[MAX_STRING_LENGTH];     //生产时间
    char category[MAX_STRING_LENGTH];           //是否处方药
};
Drug drugs[MAX_DRUGS];            //结构体数组,药品
int drugCount = 0;  //药品数量

//登陆
bool login() {
    char username[MAX_STRING_LENGTH], password[MAX_STRING_LENGTH];
    cout << "请输入用户名: ";
    cin >> username;
    cout << "请输入密码: ";
    cin >> password;
    return (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0);
}

//菜单面板
void mainMenu() {
    cout << "---------------药品管理系统-------------" << endl;
    cout << "|-          1. 增加一个药品信息       -|" << endl;
    cout << "|-          2. 删掉一个药品信息       -|" << endl;
    cout << "|-          3. 查询药品信息           -|" << endl;
    cout << "|-          4. 排序药品信息           -|" << endl;
    cout << "|-          5. 修改药品信息           -|" << endl;
    cout << "|-          6. 药品信息               -|" << endl;
    cout << "|-          7. 退出系统               -|" << endl;
    cout << "---------------药品管理系统-------------" << endl;
}

// 清屏
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    // POSIX系统 (Linux, macOS, etc.)
    cout << "\033[2J\033[1;1H";
#endif
}

//保存数据到文件
void saveDrugs(const char* filename, Drug drugs[], int drugCount) {
    ofstream file(filename);
    for (int i = 0; i < drugCount; ++i) {
        file << drugs[i].id << "\n"
            << drugs[i].name << "\n"
            << drugs[i].effect << "\n"
            << drugs[i].manufacturerName << "\n"
            << drugs[i].adminName << "\n"
            << drugs[i].productionDate << "\n"
            << drugs[i].category << "\n";
    }
    file.close();
}

//读取数据到程序
void loadDrugs(const char* filename, Drug drugs[], int& drugCount) {
    ifstream file(filename);
    drugCount = 0;

    while (drugCount < MAX_DRUGS && file >> drugs[drugCount].id) {
        file >> drugs[drugCount].name >> drugs[drugCount].effect >> drugs[drugCount].manufacturerName
            >> drugs[drugCount].adminName >> drugs[drugCount].productionDate >> drugs[drugCount].category;
        ++drugCount;
    }
    file.close();
}

//增加药品
void inputDrugInfo(const char* filename, Drug drugs[], int& drugCount) {
    if (drugCount >= MAX_DRUGS) {
        cout << "药品数量已满，无法添加更多药品。" << endl;
        return;
    }

    Drug& drug = drugs[drugCount];

    cout << "请输入药品编号: ";
    cin >> drug.id;
    //检查商品编号是否存在
    for (int i = 0; i < drugCount; i++) {
        if (strcmp(drug.id , drugs[i].id)==0){
            cout << "商品编号已存在，请重新输入！"<<endl;
            cin >> drug.id;
            i = -1;
        }
    }
    cout << "请输入药品名称: ";
    cin >> drug.name;
    cout << "请输入药品功效: ";
    cin >> drug.effect;
    cout << "请输入药品制造商名称: ";
    cin >> drug.manufacturerName;
    cout << "请输入负责该药品的管理员姓名: ";
    cin >> drug.adminName;
    cout << "请输入药品生产日期: ";
    cin >> drug.productionDate;
    cout << "请输入药品类别 (处方药/非处方药): ";
    cin >> drug.category;

    ++drugCount;
}


//删除药品
void deleteDrug(const char* drugId, Drug drugs[], int& drugCount) {
    int index = -1;
    for (int i = 0; i < drugCount; ++i) {
        if (strcmp(drugs[i].id, drugId) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "找不到指定编号的药品。" << endl;
        return;
    }

    for (int i = index; i < drugCount - 1; ++i) {
        drugs[i] = drugs[i + 1];
    }
    --drugCount;

}

//排序药品顺序
void sortDrugs(const char* key, Drug drugs[], int drugCount) {
    for (int i = 0; i < drugCount - 1; ++i) {
        for (int j = i + 1; j < drugCount; ++j) {
            bool swap = false;
            if (strcmp(key, "id") == 0 && strcmp(drugs[i].id, drugs[j].id) > 0) {
                swap = true;
            }
            else if (strcmp(key, "name") == 0 && strcmp(drugs[i].name, drugs[j].name) > 0) {
                swap = true;
            }
            else if (strcmp(key, "category") == 0 && strcmp(drugs[i].category, drugs[j].category) > 0) {
                swap = true;
            }

            if (swap) {
                Drug temp = drugs[i];
                drugs[i] = drugs[j];
                drugs[j] = temp;
            }
        }
    }
}

//修改药品数据
void modifyDrug(const char* drugId, const char* key, const char* newValue, Drug drugs[], int& drugCount, const char* filename) {
    for (int i = 0; i < drugCount; ++i) {
        if (strcmp(drugs[i].id, drugId) == 0) {
            if (strcmp(key,"name")==0) {
                strncpy(drugs[i].name, newValue, MAX_STRING_LENGTH);
            }
            else if (strcmp(key, "effect") == 0) {
                strncpy(drugs[i].effect, newValue, MAX_STRING_LENGTH);
            }
            else if (strcmp(key, "productionDate") == 0) {
                strncpy(drugs[i].productionDate, newValue, MAX_STRING_LENGTH);
            }
            else if (strcmp(key, "category") == 0) {
                strncpy(drugs[i].category, newValue, MAX_STRING_LENGTH);
            }
            break;
        }
    }

}

//查找药品数据
void searchDrugs(const char* key, const char* value, Drug drugs[], int drugCount) {
    for (int i = 0; i < drugCount; ++i) {
        bool match = false;
        if (strcmp(key, "id") == 0 && strcmp(drugs[i].id, value) == 0) {
            match = true;
        }
        else if (strcmp(key, "name") == 0 && strcmp(drugs[i].name, value) == 0) {
            match = true;
        }
        else if (strcmp(key, "manufacturerName") == 0 && strcmp(drugs[i].manufacturerName, value) == 0) { // 修改为manufacturerName  
            match = true;
        }
        else if (strcmp(key, "adminName") == 0 && strcmp(drugs[i].adminName, value) == 0) { // 添加adminName的查询  
            match = true;
        } 

        if (match) {
            // 输出药品信息，包括新的字段  
            cout << "ID: " << drugs[i].id << "\n"
                << "名称: " << drugs[i].name << "\n"
                << "功效: " << drugs[i].effect << "\n"
                << "制造商名称: " << drugs[i].manufacturerName << "\n" // 修改输出  
                << "管理员姓名: " << drugs[i].adminName << "\n" // 添加管理员姓名的输出  
                << "生产日期: " << drugs[i].productionDate << "\n"
                << "类别: " << drugs[i].category << "\n";
        }
    }
}
// 展示药品信息
void displayDrugs(const Drug drugs[], int drugCount) {
    cout << "药品信息列表：" << endl;
    for (int i = 0; i < drugCount; ++i) {
        cout << "编号: " << drugs[i].id << endl;
        cout << "名称: " << drugs[i].name << endl;
        cout << "功效: " << drugs[i].effect << endl;
        cout << "制造商名称: " << drugs[i].manufacturerName << endl;
        cout << "管理员姓名: " << drugs[i].adminName << endl;
        cout << "生产日期: " << drugs[i].productionDate << endl;
        cout << "类别: " << drugs[i].category << endl;
        cout << "-------------------" << endl;
    }
}


//终端输入输出交互
void handleMenu(Drug drugs[], int& drugCount,const char* filename) {
    int choice;
    char key[MAX_STRING_LENGTH], value[MAX_STRING_LENGTH], drugId[MAX_STRING_LENGTH];

    loadDrugs(filename, drugs, drugCount);

    while (true) {
        clearScreen();
        mainMenu();
        cout << "请选择操作: ";
        cin >> choice;
        clearScreen();
        switch (choice) {
        case 1:
            inputDrugInfo(filename, drugs, drugCount);
            break;
        case 2:
            cout << "请输入要删除的药品编号: ";
            cin >> drugId;
            deleteDrug(drugId, drugs, drugCount);
            break;
        case 3:
            cout << "请输入查询条件 (id/药名/制造商名称/是否为处方药): ";
            cin >> key;
            cout << "请输入查询值: ";
            cin >> value;
            searchDrugs(key, value, drugs, drugCount);
            cout << "查询完毕。" << endl;
            break;
        case 4:
            cout << "请输入排序条件 (id/药名/制造商名称/是否为处方药): ";
            cin >> key;
            sortDrugs(key, drugs, drugCount);
            cout << "排序完毕。" << endl;
            displayDrugs(drugs, drugCount);
            break;
        case 5:
            cout << "请输入要修改的药品编号: ";
            cin >> drugId;
            cout << "请输入要修改的属性 (id/药名/制造商名称/是否为处方药): ";
            cin >> key;
            cout << "请输入新的值: ";
            cin >> value;
            modifyDrug(drugId, key, value, drugs, drugCount, filename);
            break;
        case 6:
            displayDrugs(drugs, drugCount); // 调用 displayDrugs 函数展示药品信息
            break;
        case 7:
            cout << "--------系统退出--------";
            saveDrugs(filename, drugs, drugCount); // 保存排序后的药品列表  
            return;
        default:
            cout << "无效的选择，请重试。" << endl;
        }
        cout << "按回车键返回菜单...";
        //中断，防止输出信息被清理
        cin.ignore();
        cin.get();
    }
}


//主函数
int main() {
    if (login()) {
        handleMenu(drugs, drugCount, filename);
    }
    else {
        cout << "登录失败。" << endl;
    }
    return 0;
}