#include<iostream>
#define MAXSIZE 100
using namespace std;

typedef struct SqQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

int InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return 1;
}

int QueueLength(SqQueue *Q)
{
    return (Q->rear-Q->front);
}

int EnQueue(SqQueue *Q, int e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return 0; // 队列已满

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; // 更新 rear 指针
    return 1;
}


int DeQueue(SqQueue *Q , int *e)
{
    int fro;
    if(Q->rear==Q->front)
        return 0;
    *e=Q->data[fro];
    Q->front++;
    return 1;
}
