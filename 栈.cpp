#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 100
//顺序实现栈
struct Stack{
	int * top;
	int * end;
};

void initStack(Stack &stack){
	stack.end = new int[MAXSIZE];
	stack.top = stack.end;
}

bool isEmpty(Stack &stack){
	return stack.end == stack.top;
}

void push(Stack &stack,int element){
	*stack.top++ = element;
}

int pop(Stack &stack){
	if(isEmpty(stack)){
		return -1;
	}
	return *(--stack.top);
}


//链式实现栈
struct StackNode{
	int value;
	struct StackNode *next;
	StackNode(int value) : value(value),next(nullptr){};
	StackNode() : next(nullptr) {};
};

class ListStack{
	public:
		int size;
		StackNode *top = nullptr;
	
		ListStack(){
			this->size = 0;
			this->top = nullptr;	
		}
		~ListStack(){}	
		void listStackPush(int val){
			StackNode *temp = new StackNode(val);
			temp->next = top;
			top = temp;
			size++;
		}
		int listStackPop(){
			int pop = top->value;
			if(top->next != nullptr)	top = top->next;
			size--;
			return pop;	
		}
		bool listStackIsempty(){
			return size;
		}
		
};
int main(void){
	ListStack listStack;
	listStack.listStackPush(1);
	listStack.listStackPush(2);
	cout << listStack.listStackPop() << endl;
	cout << listStack.listStackPop() << endl;
	cout << listStack.listStackIsempty() << endl;	
	return 0;
}
