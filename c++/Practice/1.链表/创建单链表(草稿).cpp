#include "iostream"
using namespace std;

//1.单链表的定义
typedef struct LNode    //creat type 结构体类型
{   int data;                   //data field
    struct LNode *next;         //pointer field
}LNode,*LinkList;               //两者等价

//1.5创建头节点
LNode *creatLinkList()          //创建表头
{
    LNode *node=(LNode *)malloc(sizeof(LNode));  //头节点
    node->next=NULL;            //创建空表头
    return node;                //生成以node名的头节点
}
/*
 1.  sizeof(LNode)：这个表达式求得的是结构体LNode所占用的字节数。sizeof是C语言的一个操作符，
    用来获取某个类型或变量的大小（以字节为单位）。在这里，LNode是一个结构体类型，sizeof(LNode)返回的是结构体LNode的大小。
 2.  malloc(sizeof(LNode))：这是一个函数调用，malloc函数用于动态分配内存，其参数是需要分配的内存大小（以字节为单位）。
    在这里，sizeof(LNode)返回的是结构体LNode的大小，
    因此malloc(sizeof(LNode))将分配足够的内存以存储一个LNode类型的变量，并返回指向分配内存起始地址的指针。
 3.  (LNode *)：这是一个类型转换操作，将malloc返回的void *类型的指针转换为LNode *类型的指针。
    在C语言中，malloc返回的是void *类型的指针，需要根据实际情况进行类型转换。在这里，我们将其转换为指向LNode类型的指针。
 4.  LNode *node=：这是一个声明语句，将malloc返回的指针赋给LNode *类型的指针变量node。 
*/


//2.判断链表是否为空        空返回1 非空返回0
int emptyLinkList(LNode *p){
return p->next==NULL;   //空返回1 非空返回0
}

//3.计算链表中除空头节点外的节点个数
int lengthLinkList(LNode *p){
    int count = 0;
    LNode *t = p->next; 
    while(t!=NULL){
        count++;
        //cout<<count<<" : "<<t->data<<'\n'; //t是一大块，包含数据域和指针域，指针指向的是一块大空间，而非指针域或是数据域，指向后再往下才能指，不然一指域就溜走了，如果只data，那就不用->data了，如果指指针域，那直接到下一个了
        t=t->next;
    } 
    return count;
}

//4.插入新节点
int insertLinkList(LNode *p,int pos,int x)
{
    if(pos<0 ||pos>lengthLinkList(p))
    {
        return -1;
    }

    LNode *newNode=(LNode*)malloc(sizeof(LNode));
    newNode->data=x;    //赋值
    newNode->next=NULL; //暂时指向空
    LNode *t=p;         //p是一个指针，指向某个LNode类型的对象。 *p是指向的LNode对象本身。
    int i;
    for ( i = 0; i < pos-1; i++)
    {
        t=t->next;
    }
    newNode->next=t->next;
        t->next=newNode;
        return 0;

}

//5.获得某位置节点的值
int getLinkList(LNode *p,int pos)
{
    if(pos<0||pos>lengthLinkList(p)) //判断是否合法
    {
        return -1;
    }
    int i;
    LNode *t=p->next;
    for ( i = 0; i < pos; i++)
    {
        t=t->next;
    }
    return t->data;
}

//6.遍历输出链表中所有节点的值
void printLinkList(LNode *p)
{
cout<<endl;
cout<<"节点数量:"<<lengthLinkList(p)<<endl;
int count=1;
LNode *t=p->next;
while(t!=NULL)
{
    cout<<count<<":"<<t->data<<" , ";
    t=t->next;
    count++;
}
cout<<endl;
}

//7.删除链表中的节点
int deleteLinkList(LNode *p,int pos)
{
if (pos<0||pos>lengthLinkList(p))
{
    return -1;
}
int i;
LNode *t=p;
for ( i = 0; i < pos; i++)
{
   t=t->next;
}
LNode *s=t->next;   //因为要释放，所以要拿到这个节点
t->next=t->next->next;
free(s);
return 0;
}

//8.清空链表
void clearLinkList(LNode *p)
{
    while (p!=NULL)
    {
        LNode *t=p;
        p=p->next;
     free(t);
    }
}

//00.测试
int main()
{
    LNode* head= creatLinkList();   //调用创建头节点
 
    insertLinkList(head,0,10);
    insertLinkList(head,0,20);
    insertLinkList(head,2,30);
    insertLinkList(head,3,40);
    
    printLinkList(head);            //print LinkList

    insertLinkList(head,1,50);  

    cout<<"first data : "<<getLinkList(head,0);

    deleteLinkList(head, 0);

    printLinkList(head);            //print LinkList

    return 0;

}