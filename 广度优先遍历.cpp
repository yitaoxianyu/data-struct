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
		//�����ʾ������ڵ������������ͷָ��
		ArcNode *arc = G.vertices[current].firstarc;
		
		//���ȱ����͵������������Ķ���
		while(arc != nullptr){
			//arc->adjvex��ʾ�붥���������ֵ
			if(!visited[arc->adjvex]){
				visited[arc->adjvex] = 1;
				cout << G.vertices[arc->adjvex].data << " ";
				q.push(arc->adjvex);
			}
			arc = arc->nextarc;

		}
	}
}
