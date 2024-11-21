#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#define MaxInt 32676
#define MVNum 100 //最大顶点数
#define OK 1

typedef char VerTexType; //顶点类型
typedef int ArcType; //边的权值类型
typedef int Status;

#include<bits/stdc++.h>
using namespace std;

struct AMGraph{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
};

int LocateVexAMG(AMGraph G,VerTexType v);
Status CreateUDN(AMGraph &G);
void DFSUND(AMGraph G,int v);


#endif