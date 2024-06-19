#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef int ElemType;

//1.链队普通节点
typedef struct Node{
    ElemType data;
    struct Node *next;
}DataNode;

//1.5链队头节点
typedef struct 
{
    DataNode *front;    //front
    DataNode *rear;     //rear
}LinkQueue;

//2.链队初始化
LinkQueue *InitQueue()
{
    LinkQueue *q;
    q=(LinkQueue *)malloc(sizeof(LinkQueue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

LinkQueue lq = *InitQueue();    //creat

//3.
int QueueEmpty(LinkQueue *q)
{
    if(q->front==NULL && q->rear==NULL)
    {
        return 1;
    }
    else
    {
        return 0;    
    }
}

void enQueue(LinkQueue *q,ElemType e)
{
    DataNode *t;
    t=(DataNode*)malloc(sizeof(DataNode));
    t->data=e;
    t->next=NULL;

    if(q->front!=NULL||q->rear!=NULL){
        q->rear->next=t;
        q->rear=t;
    }
    else{
        q->front=t;
        q->rear=t;
    }
}

int deQueue(LinkQueue *q,ElemType *e)
{
    DataNode *t;

    if(q->front!=NULL||q->rear!=NULL)
    {
        t=q->front;
        *e=t->data;

        if(q->front->next==NULL)
        {
            q->front=NULL;
            q->rear=NULL;
        }
        else
        {
            q->front=t->next;
        }

        free(t);
        return 1;
    }
    else
    {
        cout<<"ERROR";
        return 0;
    }
}

int lengthLinkQueue(LinkQueue *q)
{
    int len;
    DataNode *t;
    if(QueueEmpty(q))
    {
        len=0;
        return len;
    }
    t=(DataNode*)malloc(sizeof(DataNode));
    t=q->front;
    len=1;
    while (t->next!=NULL)
    {
        len++;
        t=t->next;
    }
    cout<<"length="<<len;
    return len;
}

void DispQueue(LinkQueue *q)
{
    DataNode *p;
    p=q->front;
    cout<<"elem is:";
    while(p!=NULL)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}

void DestroyQueue(LinkQueue *q)
{
    //int deQueue(LinkQueue *q,ElemType *e);
    ElemType m;

    while (q->front!=NULL||q->rear!=NULL)
    {
        deQueue(q,&m);
    }
    free(q);
}

int main()
{
    LinkQueue *lq=InitQueue();

    enQueue(lq,1);
    enQueue(lq,2);
    enQueue(lq,3);
    enQueue(lq,4);
    enQueue(lq,5);
    enQueue(lq,6);
    enQueue(lq,7);
    enQueue(lq,8);
    enQueue(lq,9);
    DispQueue(lq);
    lengthLinkQueue(lq);
    ElemType e;
    deQueue(lq,&e);
    cout<<"leave elem = "<< e;
    deQueue(lq,&e);
    cout<<"leave elem = "<< e;

    cout<<"if NULL --- return 1 ,anther case --- return 0";
    cout<<endl<<QueueEmpty(lq);

    DispQueue(lq);
    lengthLinkQueue(lq);
    DestroyQueue(lq);

    return 1;

}