#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 20001
typedef int KeyType;
typedef int OtherInfo;

typedef struct {
    KeyType key;
    OtherInfo otherinfo;
}RedType;

typedef struct {
    //r表示一个序列
    RedType r [MAXSIZE + 1]; //第零个充当哨兵
    int length;
}SqList;

typedef struct Node{
    KeyType key;
    Node *next;

    Node(KeyType key,Node *next) : key(key),next(next){}
}Node;


void bubbleSort(SqList &nums);
Node* insertSort(Node *head);
void chooseSort(SqList &nums);
int parititon(SqList &nums,int left,int right);
void quickSort(SqList &nums,int left,int right);
void merge(SqList &nums,int left,int mid,int right);
void mergeSort(SqList &nums,int left,int right);
void initArray(SqList &nums,int option);
void arrayTraversal(SqList nums);
void initLinkList(Node *head);
void addNode(Node *head);


#endif

