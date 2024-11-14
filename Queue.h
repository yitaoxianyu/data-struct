#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;

typedef  ElementType;
typedef int Status;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

struct Queue {
	int rear, front;
	ElementType *elem;
};

bool isEmptyQueue(Queue queue);
bool isFullQueue(Queue queue);
void initQueue(Queue &queue);
void pushQueue(Queue &queue,ElementType val);
ElementType popQueue(Queue &queue);

#endif
