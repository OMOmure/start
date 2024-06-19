/*
1）按邻接表的方式创建一个无向连通图G，P183 图6.33；
2）采用深度遍历从顶点a出发，输出遍历顺序
3）采用广度遍历从顶点a出发，输出遍历顺序
4) 创建图的数据从文件中读取
5) 提交源代码和文件截图、运行结果的截图
*/
#include"iostream"
using namespace std;

#define OK 1
#define MaxInt 32767
typedef char VerTexType;
typedef int ArcType;

#define MVNum 100  
typedef string OtherInfo;  
typedef char VerTexType;  
typedef int ArcType;  
  
typedef struct ArcNode          //边节点
{  
    int adjvex;                 //该边指向的顶点的位置
    struct ArcNode *nextarc;    //指向下一条边的指针
    OtherInfo info;             //和边相关的指针
} ArcNode;  
  
typedef struct VNode            //顶点信息
{  
    VerTexType data;            
    ArcNode *firstarc;          //指向第一条依附节点的指针
} VNode, AdjList[MVNum];  
  
typedef struct                  //邻接表
{  
    AdjList vertices;  
    int vexnum, arcnum;         //图的顶点和边数
} ALGraph;  

int LocateVex(ALGraph &G, VerTexType v) 
{
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v) {
            return i;
        }
    }
    return -1;
}

int CreateUDG(ALGraph &G)
{
    cin>>G.vexnum>>G.arcnum;            //顶点数，总边数
    for (int i = 0; i < G.vexnum; i++)
    {
        cin>>G.vertices[i].data;        //顶点值
        G.vertices[i].firstarc=NULL;
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        int v1,v2;
        cin>>v1>>v2;    //输入一条边依附的两个节点
        int i=LocateVex(G,v1);int j=LocateVex(G,v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex=j;
        p1->nextarc=G.vertices[i].firstarc;G.vertices[i].firstarc=p1;

        ArcNode *p2=new ArcNode;
        p2->adjvex=i;
        p2->nextarc=G.vertices[j].firstarc; G.vertices[j].firstarc=p2;
    }
    return OK;
}


// 深度优先搜索  
void DFS(ALGraph G, int v, bool visited[]) 
{  
    visited[v] = true;  
    cout << G.vertices[v].data << " ";  
    ArcNode *p = G.vertices[v].firstarc;  
    while (p) {  
        int adjvex = p->adjvex;  
        if (!visited[adjvex]) {  
            DFS(G, adjvex, visited);  
        }  
        p = p->nextarc;  
    }  
}  
  
// 广度优先搜索  
void BFS(ALGraph G, int v) 
{  
    queue<int> q;
    bool visited[MVNum] = {false};  
    q.push(v);  
    visited[v] = true;  
  
    while (!q.empty()) {  
        int current = q.front();  
        q.pop();  
        cout << G.vertices[current].data << " ";  
  
        ArcNode *p = G.vertices[current].firstarc;  
        while (p) {  
            int adjvex = p->adjvex;  
            if (!visited[adjvex]) {  
                q.push(adjvex);  
                visited[adjvex] = true;  
            }  
            p = p->nextarc;  
        }  
    }  
}  
  
// 省略其他部分...  
