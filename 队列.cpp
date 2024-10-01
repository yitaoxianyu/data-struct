#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 100

struct ListNode{
	int value;
	ListNode *next;
	ListNode(int val): value(val), next(nullptr){}
};
//��ʽʵ�ֵ����ݽṹҪ����size��ΪΪ�����Ե��ڴ��޷�ͨ�������������size
class ListQueue{
	public:
		ListQueue(){
			size = 0;
			front = back = nullptr;
		}
		void push(int val){
			ListNode *temp = new ListNode(val);
			if(front == nullptr && back == nullptr) front = back = temp;
			back->next = temp;
			back = temp;
			size++;
		}
		int pop(){
			int value = front->value;
			ListNode *temp = front;
			front = front->next;	
			delete temp;
			size--;
			return value;
		}
		int peek(){
			return front->value;
		}
	
	private:
		ListNode *front;
		ListNode *back;
		int size;
};

class ArrayQueue{
	public:
		ArrayQueue(){
			front = back = new int[MAXSIZE];
		}
		void push(int val){
			if(back - front + 1 > MAXSIZE) return ;
			*back = val;
			back++;
		}
		int pop(){
			if(back - front + 1 == 0) return -1;
			int pop = *front;
			front++;
			return pop;
		}
		int peek(){
			return *front;
		}
	private:
		int *front;
		int *back;
};

int main(void){
	
	
	
	return 0;
}
