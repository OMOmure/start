#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define MVNum 100
typedef string OtherInfo;
typedef char VerTexType;
typedef int ArcType;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    OtherInfo info;
} ArcNode;

typedef struct VNode {
    VerTexType data;
    ArcNode *firstarc;
} VNode, AdjList[MVNum];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

// 从文件中读取图的数据并创建图
void CreateGraph(ALGraph &G, const char *filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Failed to open file." << endl;
        return;
    }

    fin >> G.vexnum >> G.arcnum; // 读取顶点数和边数

    VerTexType v1, v2;
    for (int i = 0; i < G.arcnum; ++i) {
        fin >> v1 >> v2; // 读取顶点之间的连接关系
        int index1 = v1 - 'a';
        int index2 = v2 - 'a';

        ArcNode *p1 = new ArcNode;
        p1->adjvex = index2;
        p1->nextarc = G.vertices[index1].firstarc;
        G.vertices[index1].firstarc = p1;

        ArcNode *p2 = new ArcNode;
        p2->adjvex = index1;
        p2->nextarc = G.vertices[index2].firstarc;
        G.vertices[index2].firstarc = p2;
    }

    fin.close();
}

// 深度优先搜索
void DFS(ALGraph &G, int v, bool visited[]) {
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
void BFS(ALGraph &G, int v) {
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

int main() {
    ALGraph G;
    CreateGraph(G, "/Users/omori/Downloads/graph.txt"); // 从文件中读取图的数据

    // 深度优先搜索从顶点'a'开始（假设'a'的索引为0）
    bool visited[MVNum] = {false};
    cout << "DFS from 'a': ";
    DFS(G, 0, visited);
    cout << endl;

    // 广度优先搜索从顶点'a'开始（假设'a'的索引为0）
    cout << "BFS from 'a': ";
    BFS(G, 0);
    cout << endl;

    return 0;
}
