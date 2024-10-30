#include "Stack.h"
#include "Queue.h"
#include<bits/stdc++.h>

using namespace std;

void initStack(Stack &stk){
	stk.top = stk.end = -1;
	stk.elem = new ElementType[MAXSIZE];
}

bool isEmptyStack(Stack stk){
	return stk.top == stk.end;
}

bool isFullStack(Stack stk){
	return stk.top++ >= MAXSIZE;
}

void pushStack(Stack &stk,ElementType val){
	if(isFullStack(stk)) return ;
	stk.elem[++stk.top] = val;
}

ElementType peekStack(Stack stk){
	if(isEmptyStack(stk)) return ERROR;
	return stk.elem[stk.top];	
}

ElementType popStack(Stack &stk){
	if(isEmptyStack(stk)) return ERROR;
	int val = peekStack(stk);
	stk.top--;
	return val;
}

void initQueue(Queue &queue){
	queue.rear = queue.front = 0;
	queue.elem = new ElementType[MAXSIZE];
}

bool isEmpty(Queue queue){
	return queue.rear == queue.front;
}

bool isFull(Queue queue){
	return (queue.rear + 1) % MAXSIZE == queue.front;
}

void pushQueue(Queue &queue,ElementType val){
	queue.elem[queue.rear] = val;
	queue.rear = (queue.rear + 1) % MAXSIZE ;
}

ElementType popQueue(Queue &queue){
	return queue.elem[queue.front--];
}

int main(void){

	return 0;
}
