#include<bits/stdc++.h>

using namespace std;

void BFS(ALGrapth G,int v){
	queue<int> q;
	cout << G.vertices[v].data << " ";
	visited[v] = 1;
	q.push(v);
	
	while(!q.empty()){
		int current = q.front();
		q.pop();
		//这个表示与这个节点相连的链表的头指针
		ArcNode *arc = G.vertices[current].firstarc;
		
		//优先遍历和弹出顶点相连的顶点
		while(arc != nullptr){
			//arc->adjvex表示与顶点相连点的值
			if(!visited[arc->adjvex]){
				visited[arc->adjvex] = 1;
				cout << G.vertices[arc->adjvex].data << " ";
				q.push(arc->adjvex);
			}
			arc = arc->nextarc;

		}
	}
}
