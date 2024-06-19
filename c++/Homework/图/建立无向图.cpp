/*1）按邻接表的方式创建一个无向连通图G，P183 图6.33；
2）采用深度遍历从顶点a出发，输出遍历顺序；
3）采用广度遍历从顶点a出发，输出遍历顺序。
4)  创建 图的数据从文件中读取
5) 提交源代码和文件截图、运行结果的截图*/
#include<iostream>
#include<fstream>  
#include<cstring>  
#include<queue>  
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef string OtherInfo;
typedef char VerTexType;
typedef int ArcType;

typedef struct ArcNode
{
   int adjvex;
   struct ArcNode *nextarc;
   OtherInfo info;
}ArcNode;

typedef struct VNode
{
    VerTexType data;
    ArcNode *firstarc;
}VNode,AdjList[MVNum];

typedef struct 
{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

