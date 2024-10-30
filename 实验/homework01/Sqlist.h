#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef int Status;

#define OK 1
#define ERROR 0
#define MAXSIZE 100

struct Sqlist {
    ElementType *elem;
    int size; // ��ǰ����
    int capacity; // �������
};

struct LinkListNode{
    ElementType val;
    LinkListNode *next;
    LinkListNode(int val) : val(val),next(nullptr){};
};

struct LinkList{
    LinkListNode *head;
    int size;
    int capacity;
};
Status initSqlist(Sqlist &L);
Status insert(int index,int val,Sqlist &L);
Status delete_LinkList(int index,Sqlist &L);
Status update(int index,int val,Sqlist &L);
int find(int val,Sqlist &L); //�����ҵ���һ��Ԫ�ص�����

Status initLinkList(LinkList &L);
Status insertNode(int val,LinkList &L); //����ͷ�巨
Status deleteNode(int val,LinkList &L);
LinkListNode *findNode(int val,LinkList &L);
void unionSqlist(Sqlist &l1, Sqlist &l2, Sqlist &l3);
void IntersectionSqlist(Sqlist &l1,Sqlist &l2,Sqlist &l3);
#endif // SQLIST_H_INCLUDED
