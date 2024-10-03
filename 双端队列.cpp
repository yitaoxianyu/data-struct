#include<bits/stdc++.h>

using namespace std;

struct DoublyListNode{
	int val;
	DoublyListNode *next;
	DoublyListNode *prev;
	DoublyListNode(int val) : val(val),next(nullptr),prev(nullptr){}
};

class LinkedListDequeue{
	private:
	DoublyListNode *front, *rear;
	int queSize = 0;
	
	public:
		LinkedListDequeue() : front(nullptr), rear(nullptr){}
		~LinkedListDequeue(){
			DoublyListNode *pre, *cur = front;
			while(cur != nullptr){
				pre = cur;
				cur = cur->next;
				delete pre;
			}
		}
		int size(){
			return queSize;
		}
		
		bool isEmpty(){
			return size() == 0;
		}
		void push(int num,bool isFront){
			DoublyListNode *node = new DoublyListNode(num);
			if(isEmpty()){
				front = rear = node;
			}
			else if(isFront){
				front->prev = node;
				node->next = front;
				front = node;
			}
			else{
				rear->next = node;
				node->prev = rear;
				rear = node;
			}
			queSize++;
		}
		void pushFirst(int num){
			push(num,true);
		}
		void pushLast(int num){
			push(num,false);
		}
		
		int pop(bool isFront){
			if(isEmpty()) throw out_of_range("队列为空");
			int val;
			if(isFront){
				val = front->val;
				DoublyListNode *fNext = front->next;
				if(fNext != nullptr){
					fNext->prev = nullptr;
					front->next = nullptr;					
				}
				delete front;
				front = fNext;
			}
			else{
				val = rear->val;
				DoublyListNode *fPre = rear->prev;
				if(fPre != nullptr){
					fPre->next = nullptr;
					rear->prev = nullptr;
				}
				delete rear;
				rear = fPre;
			}
			queSize--;
			return val;
		}
		int popLast(){
			return pop(false);
		}
		int popFirst(){
			return pop(true);
		}
		int peekFirst(){
			if(isEmpty())
				throw out_of_range("双向队列为空");
			return front->val;
		}
		int peekLast(){
			if(isEmpty())
				throw out_of_range("双向队列为空");
			return rear->val;
		}
		vector<int> toVector(){
			DoublyListNode *node = front;
			vector<int>res(size());
			for(int i = 0;i < (int)res.size();i ++){
				res[i] = node->val;
				node = node->next;
			}
			return res;
		}

};






int main(void){
	
	
	
	return 0;
}
