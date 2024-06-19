#include<iostream>
using namespace std;
typedef int LTDataType;

//1.双向链表定义
typedef struct ListNode     //定义指针直接扒这一段
{
    struct ListNode *prev;  //prev 是一个指向 struct ListNode 类型的指针，而不是 int 类型的。解释了为什么指向一个节点（结构体）
    LTDataType Data;
    struct ListNode *next;
}ListNode;                  //typedef是c语言中，在此的作用为将struct ListNode改名为ListNode，后续可以直接用ListNode这个类型定义变量

//2.双向链表的初始化
ListNode *ListInit()
{
    ListNode *guard=(ListNode *)malloc(sizeof(ListNode));   //一个头节点分配一个，如果是两个，就✖️2
    if(guard==NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    guard->next=guard;
    guard->prev=guard; 
    
    return guard;
}


//双向链表的初始化，不需要二级指针，利用返回值
ListNode *listNode=ListInit();//use return data ,need no twice pointer


//3.双向链表的创建一个新节点
ListNode *BuyListNode(LTDataType x)
{
    ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
    /*if(newnode==NULL)
    {
        perror("malloc fail");
        exit(-1);
    }*/
    newnode->Data=x;
    newnode->prev=NULL;
    newnode->next=NULL;

    return newnode;
}

//4.双向链表的打印
void ListPrint(ListNode* phead)
{
    assert(phead!=null);

    ListNode *cur = phead -> next;
    cout<<"guard<=>";
    while(cur!=phead)
    {
    //cout<<cur->Data;
    printf("%d<=>",cur->Data);
    cur=cur->next;
    }
    cout<<endl;
}

//5.双向链表的尾插
void ListPushBack(ListNode *phead , LTDataType x)
{
    assert(phead!=null);
    
    //创造节点
    ListNode *newnode = BuyListNode(x); //待插入的新节点
    ListNode *tail = phead->prev;       //链表尾部
    //记录尾的前一个
    phead->prev=newnode;    //新节点与头节点
    newnode->next=phead;    //新节点与头节点
    newnode->prev=tail;
    tail->next=newnode;
}

//6.双向链表的尾删
void ListPopBack(ListNode *phead)
{
    assert(phead!=null)
    ListNode *tail = phead -> prev;
    //记录前一个
    ListNode *prev = tail -> prev;
    phead->prev=prev;
    prev->next=phead;
    free(tail)
    tail=NULL;
}

//7.双向链表的头插
void ListPushFront(ListNode *phead , LTDataType x)
{
    assert(phead!=null);

    ListNode *newnode = BuyListNode(x);
    //记录phaed的后一个
    ListNode *next = phead->next;

    phead->next = newnode;
    newnode->next=next;

    next-->prev=newnode;
    newnode->prev=phead;
}

//8.双向链表的长度
int ListSize(ListNode* phead)
{
    assert(phead!=null);
    int count = 0;

    ListNode *cur = phead -> next;
    while(cur!=phead)
    {
        count++;
        cur=cur->next;
    }
    return count;
}

//9.求双向链表的查找某个值
ListNode ListFind(ListNode* phead , LTDataType x)
{
    assert(phead!=null);
   
    ListNode *cur = phead -> next;
    while(cur!=phead)
    {
        if (cur->Data==x)
        {
            return cur;
        }
        cur=cur->next;
    }
    //no find
    return count;
}

//10.双向链表在pos之前插入
void ListInsert(ListNode *pos , LTDataType x)   //有listnode * 不是int型，所以不需要遍历
{
    assert(pos);
    //记录pos的前一个
    ListNode *prev = pos->prev;
    ListNode *newnode= BuyListNode(x);

    prev->next = newnode;
    newnode->next=pos;

    pos->prev=newnode;
    newnode->prev=prev;
}

//11.双向链表删除pos位置
void ListErase(ListNode *pos)
{
    assert(pos);
    //记录前一个与后一个
    ListNode *prev = pos->prev;
    ListNode *next = pos->next;

    prev->next=next;
    next->prev = prev;

    free(pos);
    pos=NULL;
}

//12.双向链表的销毁
void ListDestroy(ListNode *phead)
{
    assert(phead)
    //遍历销毁
    ListNode *cur = phead->next;
    while (cur!=phead)
    {
        ListNode *next = cur->next; //要留下记号，直接释放拿不到cur->next
        free(cur);
        cur = next;
    }
    free(phead);
}