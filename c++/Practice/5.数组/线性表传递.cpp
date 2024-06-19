#include<iostream>
using namespace std;
#define MAXSIZE 10 

//1.线性表静态定义 
typedef struct
{
    int data[MAXSIZE];  
    int length;         //当前表长
}Sqlist;

//2.线性表静态初始化
void InitList(Sqlist &L)    
{
    for (int i = 0; i < MAXSIZE; i++)
        L.data[i]=2;
    L.length=10;
}

int main()      //测试函数
{
  Sqlist L;
  InitList(L);

    for (int i = 0; i < MAXSIZE; i++)
       cout<<i<<":"<<L.data[i]<<endl;
   
return 0;
}

/*
void InitList(Sqlist L) 
在 main 函数中，你声明了一个名为 InitList 的函数，
但是没有正确调用它。这导致程序中实际调用的是全局范围内的 InitList 函数，
而不是你定义的那个用来初始化列表的函数。

🌟tips：调用结构体时，主函数不引用，被调用的函数引用（且定义类型）

❌
int main()      //测试函数
{
    Sqlist L;
    void InitList(Sqlist L); 
    for (int i = 0; i < MAXSIZE; i++)
        cout<<i<<":"<<L.data[i]<<endl;
    return 0;
}

}
✅
int main()      //测试函数
{
    Sqlist L;
    InitList(L);
    for (int i = 0; i < MAXSIZE; i++)
        cout<<i<<":"<<L.data[i]<<endl;
    return 0;
}
*/
