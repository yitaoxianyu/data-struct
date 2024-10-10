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
		//没有使用size来计数，所以只能使用capacity - 1的长度
		bool isFull(){
			return index(rear + 1) == front;
		}
		void push(int val){
			if(isFull()){
				cout << "队列已满！" << endl;
				return ;
			}
			nums[rear] = val;
			rear = index(rear + 1);
			return ;
		}
		int pop(){
			if(isEmpty()){
				cout << "队列为空！" << endl;
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
