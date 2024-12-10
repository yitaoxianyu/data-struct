//这里为了防止被源文件重复导入使用头文件保护
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;

typedef int Status;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

struct TreeNode{
    TreeNode *lChild;
    TreeNode *rChild;
    char data;
};

typedef TreeNode * Tree;

void createTree(Tree &root);
void preOrder(Tree root);
void inOreder(Tree root);
void postOrder(Tree root);
int leafNode(Tree root);
int depth(Tree root);

#endif