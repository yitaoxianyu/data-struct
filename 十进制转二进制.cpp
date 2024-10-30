#include <bits/stdc++.h>

using namespace std;


#define MaxSize 100        /* ջ������� */

int top;                /* ջ��ָ�� */

int mystack[MaxSize];    /* ˳��ջ */


/*��ջ�Ƿ�Ϊ�գ��շ���true���ǿշ���false */

bool isEmpty();


/* Ԫ��x��ջ */

void Push(int x);


/* ȡջ��Ԫ�� */

int getTop();


/* ɾ��ջ��Ԫ�� */

void Pop();


/* ʮ����������ת��Ϊ������ */

void dec2bin(int x) {

    top = -1;            /* ��ʼ��ջ��ָ�� */

    while (x) {

        Push(x % 2);

        x >>= 1;

    }

    while (!isEmpty()) {

        int t = getTop();

        Pop();

        printf("%d", t);

    }

    printf("\n");

}


int main(int argc, char const *argv[])

{

    int n;

    while (scanf("%d", &n) != EOF) {

        dec2bin(n);

    }

    return 0;

}
bool isEmpty(){
	return top == - 1;
}


/* Ԫ��x��ջ */

void Push(int x){
	if(top >= MaxSize - 1){
		return ;
	}
	top ++;
	mystack[top] = x;
}


/* ȡջ��Ԫ�� */

int getTop(){
	if(!isEmpty())
	return mystack[top];
}


/* ɾ��ջ��Ԫ�� */

void Pop(){
	if(isEmpty()){
		return ;
	}
	top--;
}
