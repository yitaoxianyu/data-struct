#include<bits/stdc++.h>
#include "Matrix.h"
#include "List.h"

using namespace std;

int LocateVexAMG(AMGraph G,VerTexType v){
    for(int i = 0;i < G.vexnum;i ++){
        if(G.vexs[i] == v) return i;
    }
    return -1;
}

int locateVexUNG(ALGraph G,VerTexType v){
        for(int i = 0;i < G.vexnum;i ++){
        if(G.vertices[i].data == v) return i;
    }
    return -1;
}

Status CreateUDN(AMGraph &G){
        cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i ++) cin >> G.vexs[i]; // 录入顶点信息

    for(int i = 0;i < G.vexnum;i ++){
        for(int j = 0;j < G.vexnum;j ++){
            G.arcs[i][j] = MaxInt;
        }
    } //初始化邻接矩阵，权值都为无穷大

    for(int i = 0;i < G.arcnum;i ++){
        ArcType w; VerTexType v1, v2; cin >> v1 >> v2 >> w;
        
        int m = LocateVexAMG(G,v1); int n = LocateVexAMG(G,v2);
        G.arcs[m][n] = w;
        G.arcs[n][m] = G.arcs[m][n];
    }

    return OK;   
};

Status CreateUDG(ALGraph &G){
    //邻接表创建一个图
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i ++){
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }

    for(int k = 0;k < G.arcnum;k ++){
        VexTexType v1, v2; cin >> v1 >> v2;
        int i = LocateVexUDG(G,v1); int j = LocateVexUDG(G,v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;

        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;  
    }

    return OK;
}

void DFS(ALGraph G,int v){
    cout << v;visited[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while(p != nullptr){
        int w = p->adjvex;
        if(!visited[w]) DFS(G,w);
        p = p->nextarc;
    }
}

void BFS(ALGraph G,int v){
    cout << v;visited[v] = true;
    Queue que;
    initQueue(que);
    pushQueue(que,v);
    while(!isEmpty(que)){
        int u = popQueue(que);
        visited[u] = true;
        for(ArcNode *temp = G.vertices[u].firstarc;temp != nullptr;temp = temp->nextarc){
            if(!visited[temp->adjvex]){
                cout << temp->adjvex;
                pushQueue(que,temp->adjvex);
            }
        }
    }
}

void initQueue(Queue &queue){
	queue.rear = queue.front = 0;
	queue.elem = new ElementType[MAXSIZE];
}

bool isEmpty(Queue queue){
	return queue.rear == queue.front;
}

bool isFull(Queue queue){
	return (queue.rear + 1) % MAXSIZE == queue.front;
}

void pushQueue(Queue &queue,ElementType val){
	queue.elem[queue.rear] = val;
	queue.rear = (queue.rear + 1) % MAXSIZE ;
}

ElementType popQueue(Queue &queue){
    ElementType val = queue.elem[queue.front];
    queue.front = (queue.front + 1) % MAXSIZE;
	return val;
}

ElementType getHead(Queue queue){
    if(!isEmptyQueue(queue))  return queue.elem[queue.front];
}
