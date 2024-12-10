#include<bits/stdc++.h>
#include "Sqlist.h"

using namespace std;

Status initSqlist(Sqlist &L){
    L.capacity = MAXSIZE;
    L.size = 0;
    L.elem = new ElementType[MAXSIZE];
    return OK;
}
Status insert(int index,int val,Sqlist &L){
    if(index > L.size) return ERROR;
    int limit = L.size;
    for(int j = limit;j >= index;j --){
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[index] = val;
    L.size ++;
    return OK;
}
Status delete_LinkList(int index,Sqlist &L){
    if(index >= L.size) return ERROR;
    //index´ú±íË÷Òý
    int limit = L.size - 1;
    for(int i = limit ;i > index;i ++){
        L.elem[i - 1] = L.elem[i];
    }
    L.size --;
    return OK;
}
Status update(int index,int val,Sqlist &L){
    if(index >= L.size) return ERROR;
    L.elem[index] = val;
    return OK;
}
int find(int val,Sqlist &L){
    for(int i = 0;i < L.size;i ++){
        if(L.elem[i] == val) return i;
    }
    return -1;
}
Status initLinkList(LinkList &L){
    L.capacity = MAXSIZE;
    L.size = 0;
    LinkListNode *newNode = new LinkListNode(-1);
    L.head = newNode;
    return OK;
}
Status insertNode(int val,LinkList &L){
    if(L.size >= L.capacity) return ERROR;
    LinkListNode *newNode = new LinkListNode(val);
    newNode -> next = L.head -> next;
    L.head ->next = newNode;
    return OK;
}
Status deleteNode(int val,LinkList &L){
    LinkListNode *cur = L.head;
    while(cur -> next != nullptr){
        if(cur -> next -> val == val){
            cur -> next = cur -> next -> next;
            break;
        }
        cur = cur -> next;
    }
    if(cur -> next == nullptr) return ERROR;
    else return OK;
}
LinkListNode* findNode(int val,LinkList &L){
    LinkListNode *cur = L.head -> next;
    while(cur != nullptr){
        if(cur -> val == val){
            return cur;
        }
        cur = cur -> next;
    }
    return nullptr;
}
Status updateNode(int val,LinkListNode *target,LinkList &L){
    LinkListNode *cur = L.head;
    while(cur != nullptr){
         if(cur == target){
            cur -> val = val;
            return OK;
         }
        cur = cur -> next;
    }
    return ERROR;
}

void unionSqlist(Sqlist &l1,Sqlist &l2,Sqlist &l3){
	initSqlist(l3);
	int size1 = l1.size, size2 = l2.size;
	for(int i = 0;i < size1;i ++){
		insert(i,l1.elem[i],l3);
	}
	for(int j = 0;j < size2;j ++){
		if(find(l2.elem[j],l3) == -1){
			insert(size1 + j - 1,l2.elem[j],l3);
		}
	}
}

void IntersectionSqlist(Sqlist &l1,Sqlist &l2,Sqlist &l3){
	initSqlist(l3);int size1 = l1.size;
	int index = 0;
	for(int i = 0;i < size1;i ++){
		if(find(l1.elem[i],l2) != -1){
			insert(index,l1.elem[i],l3);
			index++;
		}
	}
	
}
int main()
{
	return 0;
}
