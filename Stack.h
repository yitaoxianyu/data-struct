#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<bits/stdc++.h>

using namespace std;

typedef Tree ElementType;
typedef int status;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

struct Stack{
	int top, end;
	ElementType *elem;
};

void initStack(Stack &stk);
void pushStack(Stack &stk,ElementType val);
ElementType popStack(Stack &stk);
ElementType peekStack(Stack stk);
bool isEmptyStack(Stack stk);
bool isFullStack(Stack stk);

#endif
