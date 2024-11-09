#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<bits/stdc++.h>

using namespace std;

typedef int status;
typedef int ElementType;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

struct Stack{
	int top, end;
	ElementType *elem;
};

void initStack(Stack &stk);
void pushStack(Stack &stk,ElementType val);
int popStack(Stack &stk);
int peekStack(Stack stk);
bool isEmptyStack(Stack stk);
bool isFullStack(Stack stk);

#endif
