#include<bits/stdc++.h>
using namespace std;


typedef struct Sqlist{
	int * elem = NULL; 	
	int length = 0;
	int capacity = 0;
}Sqlist;

void initSqlist(int len,Sqlist &sqList){
	sqList.elem = new int[len];
	sqList.capacity = len;
}

//在第i个位置插入元素e
void insertSqlist(int i,Sqlist &sqList,int e){
	for(int j = sqList.length - 1;j >= i - 1;j--) sqList.elem[j + 1] = sqList.elem[j];
	sqList.elem[i - 1] = e;
	sqList.length++; 
}
//删除第i个位置的元素
void deleteSqlist(int i,Sqlist &sqList){
	for(int j = i;j <= sqList.length - 1;j++) sqList.elem[j - 1] = sqList.elem[j];
	sqList.length--;
}



typedef struct ListNode{
	struct ListNode *next;
	int value;
} ListNode,* LinkList;


//初始化链表
void initLinkList(LinkList &L){
	L = new ListNode;
	L->next = NULL;
	L->value = 0;	
}

//插入节点,头插
void insertLinkList_Head(LinkList &L,int len){
	for(int i = 0;i < len;i ++){
		LinkList temp = new ListNode;
		int value; cin >> value; 
		temp->value = value;
		temp->next  = L->next;
		L->next = temp;
	}	
	
}


//插入节点尾插
void insertLinkList_Tail(LinkList &L,int len){
	LinkList p = L;	
	for(int i = 0;i <len;i ++){
		LinkList temp = new ListNode;
		int value; cin >> value;
		p->next  = temp;
		p = temp;
	}
		
}


//查倒数第i个数，倒数第i个数就是整数第len - i + 1个数
void searchLinkList(LinkList &L,int i){
	//双指针
	LinkList first = L;
	LinkList second = L;
	//首先让快指针走i步
	for(int j = 1;j <= i;j ++) first = first->next;
	
	//让快指针走到最后一个指针的下一个
	while(first){
		first = first->next;
		second = second->next;
	}
	//此时scond指向的就是倒数第i个
}








int main(void){
 	return 0;

}
