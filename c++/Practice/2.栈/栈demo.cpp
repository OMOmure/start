#include<iostream>
#include<string>
using namespace std;
typedef int SDataType;
#define STACK_INIT_SIZE 100
#define OK 1
#define ERROR -1
#define MAXSIZE 100
//1.定义
typedef struct{
    SDataType *base;
    SDataType *top;
    int StackSize;
}SqStack;

//2.初始化栈
int InitStack(SqStack &s)
{
    s.base=new SDataType[MAXSIZE];     //FENPEI
    if(!s.base)  return OVERFLOW;   //check
    s.top=s.base;                   
    s.StackSize = MAXSIZE;      
    return OK;
}

//3.判断是否为空栈
void judgeNull(SqStack &s){
    if(s.top == s.base){
        cout<<"为空栈"<<endl;;
    } else{
        cout<<"不为空栈" <<endl;
    }
}

//4.判断是否为满栈
void judgeFull(SqStack &s){
    if(s.top-s.base == s.StackSize){
        cout<<cout<<"栈满"<<endl;
    }else{
        cout<<"栈未满" <<endl;
    }
}

//5.入栈
int Push(SqStack &S,SDataType e)
{
    if(S.top-S.base == S.StackSize) return OVERFLOW;
    *S.top++=e;
    return OK;
}
//6.出栈
int Pop(SqStack &S, SDataType &e) 
{
    if (S.top == S.base) return ERROR;  // 栈空
    e = *--S.top;                        // 出栈并返回栈顶元素
    return OK;
}
//7.取栈顶元素
void GetTop(SqStack &S)
{
    if(S.top == S.base) 
    {
        cout << "栈为空" << endl; 
    } 
    else 
    {
        cout<<"栈顶元素为："<<*(S.top-1);
    }
}

int main(){
    SqStack s;
    SDataType e;
    InitStack(s);
    Push(s,1);
    Push(s,2);
    Push(s,3);
    GetTop(s);

    //cout<<"栈顶元素为："<<GetTop(s)<<endl;
    /*
    //once pop
    Pop(s,e);
    cout<<"出栈元素为："<<e<<endl;
    cout<<"栈顶元素为："<<GetTop(s)<<endl;
    //twice pop
    Pop(s,e);
    cout<<"出栈元素为："<<e<<endl;
    cout<<"栈顶元素为："<<GetTop(s)<<endl;
    //second pop
    Pop(s,e);
    cout<<"出栈元素为："<<e<<endl;
    */
    //cout<<"栈顶元素为：";

    
    //once pop
    Pop(s,e);
    cout<<endl<<"出栈元素为："<<e<<endl;
    GetTop(s);
    //twice pop
    Pop(s,e);
    cout<<endl<<"出栈元素为："<<e<<endl;
    GetTop(s);
    //second pop
    Pop(s,e);
    cout<<endl<<"出栈元素为："<<e<<endl;
    GetTop(s);
   
    cout<<"check:";judgeNull(s);
    cout<<"check:";judgeFull(s);
    return 0;
}