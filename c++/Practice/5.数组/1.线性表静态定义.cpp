#include<iostream>
using namespace std;
#define MAXSIZE 100  
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
        L.data[i]=i;
    L.length=0;
}

//3.线性表的插入
bool IistInsert(Sqlist &L,int i,int e)
{
    if(i<1||i>L.length)
        return false;
    if(L.length>=MAXSIZE)
        return false;
    int j;
    for (int j = L.length; j>=i; j--)
       L.data[j]=L.data[j-1];
    L.data[j]=e;
    L.length++;
    return true;
}

//4.线性表的删除
bool ListDelete(Sqlist  &L ,int j,int &e)
{

}



//00.测试函数
int main()     
{
  Sqlist L;
  InitList(L);

    for (int i = 0; i < MAXSIZE; i++)
       cout<<i<<":"<<L.data[i]<<endl;
   
return 0;
}
