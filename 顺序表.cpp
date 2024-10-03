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

//�ڵ�i��λ�ò���Ԫ��e
void insertSqlist(int i,Sqlist &sqList,int e){
	for(int j = sqList.length - 1;j >= i - 1;j--) sqList.elem[j + 1] = sqList.elem[j];
	sqList.elem[i - 1] = e;
	sqList.length++; 
}
//ɾ����i��λ�õ�Ԫ��
void deleteSqlist(int i,Sqlist &sqList){
	for(int j = i;j <= sqList.length - 1;j++) sqList.elem[j - 1] = sqList.elem[j];
	sqList.length--;
}



typedef struct ListNode{
	struct ListNode *next;
	int value;
} ListNode,* LinkList;


//��ʼ������
void initLinkList(LinkList &L){
	L = new ListNode;
	L->next = NULL;
	L->value = 0;	
}

//����ڵ�,ͷ��
void insertLinkList_Head(LinkList &L,int len){
	for(int i = 0;i < len;i ++){
		LinkList temp = new ListNode;
		int value; cin >> value; 
		temp->value = value;
		temp->next  = L->next;
		L->next = temp;
	}	
	
}


//����ڵ�β��
void insertLinkList_Tail(LinkList &L,int len){
	LinkList p = L;	
	for(int i = 0;i <len;i ++){
		LinkList temp = new ListNode;
		int value; cin >> value;
		p->next  = temp;
		p = temp;
	}
		
}


//�鵹����i������������i��������������len - i + 1����
void searchLinkList(LinkList &L,int i){
	//˫ָ��
	LinkList first = L;
	LinkList second = L;
	//�����ÿ�ָ����i��
	for(int j = 1;j <= i;j ++) first = first->next;
	
	//�ÿ�ָ���ߵ����һ��ָ�����һ��
	while(first){
		first = first->next;
		second = second->next;
	}
	//��ʱscondָ��ľ��ǵ�����i��
}



//��ʮ��

void deleteItem(vector<int> nums,int item){
	//˫ָ��	
	int i = 0, j = 0;
	while(j < (int)nums.size()){
		if(nums[j] != item){
			nums[i] = nums[j];
			i++; 
		}
		j++;
	}
}




int main(void){
 	return 0;

}
