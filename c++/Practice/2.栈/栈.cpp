#include<iostream>
using namespace std;
typedef int SDataType;
#define STACK_INIT_SIZE 100
#define OK 1
#define MAXSIZE 100
//1.栈的定义
typedef struct{
    SDataType *base;
    SDataType *top;
    int StackSize;
}SqStack;

//2.初始化栈
int InitStack(SqStack &s)
{
     s.base=new SqStack[MAXSIZE]
    //s.base=(SDataType *)malloc(STACK_INIT_SIZE*sizeof(SDataType));
    if(!s.base)
    {
        return OVERFLOW;
    }
    s.top=s.base;
    s.StackSize = STACK_INIT_SIZE;
    return OK;
}
//3.判断是否为空栈
void judgeNull(SqStack &s)
{
    if(s.top == s.base)
    {
        cout<<"空栈";
    }
    else
    {
        cout<<"不为空栈" ;
    }
}

//4.判断是否为满栈
void judgeFull(SqStack &s)
{
    if(s.top-s.base == s.StackSize)
    {
        cout<<cout<<"栈满";
    }
    else
    {
        cout<<"栈未满" ;
    }
}

//5.入栈
int Push(SqStack &s,SDataType e)
{
    SDataType *p;
    if(s.top-s.base == s.StackSize)
    //add space
    {
        int STAKCINCREMENT;
        p= (SDataType *)realloc(s.base,(s.StackSize + STAKCINCREMENT)*sizeof(SDataType));
        if(!p) //if have no space to add
            return OVERFLOW;
        
        s.base = p;
        s.top = s.base + s.StackSize;
        s.StackSize += STACKINCREMENT;
    }
    *(s.top)=e;
    s.top++;
    return OK;
}

//6.出栈
Status Pop(SqStack &S,)