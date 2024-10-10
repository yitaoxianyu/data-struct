#include<bits/stdc++.h>

using namespace std;

class queue{
	private:
		int front;
		int queueSize;
		int capacity;
		vector<int> nums;
	public:
		queue(int capacity){
			this->capacity = capacity;
			this->front = 0;
			this->queueSize = 0;
			nums.resize(capacity);
		}
		int index(int x){
			return (x + capacity) % capacity;
		}
		bool isEmpty(){
			return queueSize == 0;
		}
		bool isFull(){
			return queueSize == capacity;
		}
		void push(int val){
			if(isFull()){
				cout << "����������" << endl;
			}
			int rear = index(front + queueSize);
			nums[rear] = val;
			queueSize++;
		}
		int pop(){
			if(isEmpty()){
				cout << "����Ϊ�գ�" << endl;
			}
			int val = nums[front];
			front = index(front + 1);
			queueSize--;
			return val;
		}
};




int main(void){
	
		
	
	
	return 0;
}
