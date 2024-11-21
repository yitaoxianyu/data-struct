#ifndef LIST_H_INDLUCED
#define LIST_H_INCLUDED

#include<bits/stdc++.h>

using namespace std;

#define MVNnum 100
#define MAXSIZE 100
#define OK 1
#define ERROR 0



typedef char VexTexType;
typedef int ArcType;
typedef int Status;
typedef int ElementType;


struct ArcNode{
    int adjvex;
    ArcNode *nextarc;
    //此属性没有用
    ArcType weight;
};

struct VNode{
  VexTexType data;
  ArcNode *firstarc;  
};

struct ALGraph{
    VNode vertices[MVNnum];
    int vexnum, arcnum;
};
struct Queue {
	int rear, front;
	ElementType *elem;
};
int LocateVexUDG(ALGraph G,VexTexType v);
Status CreateUDG(ALGraph &G);

bool visited[MVNnum]; //标志数组
void DFS(ALGraph G,int v);
void BFS(ALGraph G);

bool isEmptyQueue(Queue queue);
bool isFullQueue(Queue queue);
void initQueue(Queue &queue);
void pushQueue(Queue &queue,ElementType val);
ElementType popQueue(Queue &queue);


#endif