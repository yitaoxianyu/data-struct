#include <stdio.h>

#include <stdlib.h>

typedef char DataType;

struct Queue

{

    int Max;  

    int f;   

    int r;  

    DataType *elem; 

};

typedef struct Queue *SeqQueue;


SeqQueue SetNullQueue_seq(int m) 

{

    SeqQueue squeue;

    squeue = (SeqQueue)malloc(sizeof(struct Queue));

    if (squeue == NULL)

    {

        printf("Alloc failure\n");

        return NULL;

    }

    squeue->elem = (char*)malloc(sizeof(DataType)*m);

    if (squeue->elem != NULL)

    {

        squeue->Max = m;

        squeue->f = 0;

        squeue->r = 0;

        return squeue;

    }

}


int IsNullQueue_seq(SeqQueue squeue) 

{

    return (squeue->f == squeue->r);

}

void EnQueue_seq(SeqQueue squeue, DataType x);  
void DeQueue_seq(SeqQueue squeue);  
DataType FrontQueue_seq(SeqQueue squeue); 
int main()

{

    char ch;

    SeqQueue queueA = SetNullQueue_seq(5);

    ch = getchar();

    while (ch != '#')

    {

        EnQueue_seq(queueA, ch);

        ch = getchar();

    }

    DeQueue_seq(queueA);

    printf("%c" ,FrontQueue_seq(queueA));

    return 0;

}

int isFullQueue_seq(SeqQueue squeue){
	return 	((squeue->r + 1) % squeue->Max == squeue->f);
}

void Enqueue_seq(SeqQueue squeue,DataType x){
	if(isFullQueue_seq(squeue)){
		printf("It is FULL Queue");
			return ;	
	}
	squeue->elem[squeue->r] = x;
	squeue->r = (squeue->r + 1) % squeue->Max;
}

void Dequeue_seq(SeqQueue squeue){
	if(IsNullQueue_seq(squeue)){
		printf("It is empty queue!");
		return ;
	}
	squeue->f = (squeue->f + 1) % squeue->Max;
}

DataType FrontQueue_seq(SeqQueue squeue){
	return squeue->elem[squeue->f];
}

