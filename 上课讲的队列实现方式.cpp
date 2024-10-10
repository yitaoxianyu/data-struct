#include<bits/stdc++.h>

using namespace std;

class queue{
	private:
		int front;
		int rear;
		int capacity;
		vector<int> nums;
	public:
		queue(int capacity)
		{
			this->front = 0;
			this->rear = 0;
			this->capacity = capacity;
			nums.resize(capacity);
		}
		int index(int x){
			return (x + capacity) % capacity;
		}
		bool isEmpty(){
			return front == rear;
		}
		//û��ʹ��size������������ֻ��ʹ��capacity - 1�ĳ���
		bool isFull(){
			return index(rear + 1) == front;
		}
		void push(int val){
			if(isFull()){
				cout << "����������" << endl;
				return ;
			}
			nums[rear] = val;
			rear = index(rear + 1);
			return ;
		}
		int pop(){
			if(isEmpty()){
				cout << "����Ϊ�գ�" << endl;
				return -1;
			}
			int val = nums[front];
			front = index(front + 1);
			return val;
		}
		int peek(){
			return nums[front];
		}
};



int main(void){
	
	
	return 0;
}
