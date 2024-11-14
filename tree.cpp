#include "Tree.h"
#include "Stack.h"
#include "Queue.h"
#include<bits/stdc++.h>

using namespace std;

int main(void){
    Tree tree = nullptr;
    createTree(tree);
    preOrder(tree);
    return 0;
}

void createTree(Tree &root){
    char ch; cin >> ch;
    if(ch == '#'){
        root = nullptr;
        return ;
    }
    root = new TreeNode();
    root->data = ch;
    createTree(root->lChild);
    createTree(root->rChild);
}

void preOrder(Tree root){
    if(root == nullptr) return ;
    cout << root->data;
    preOrder(root->lChild);
    preOrder(root->rChild);
}

void inOrder(Tree root){
    if(root == nullptr) return ;
    inOrder(root->lChild);
    cout << root->data;
    inOrder(root->rChild);
}

void postOrder(Tree root){
    if(root == nullptr) return ;
    postOrder(root->lChild);
    postOrder(root->rChild);
    cout << root->data;
}

void preOrderNoRecursion(Tree root){
    if(root == nullptr) return ;
    stack<Tree> stk;
    while(root != nullptr || !stk.empty()){
        if(root != nullptr){
            cout << root->data;
            stk.push(root);
            root = root->lChild;
        }
        else{
            root = stk.top(); stk.pop();
            root = root->rChild;
        }
    }

}

void inOrderNoRecursion(Tree root){
    if(root == nullptr) return ;
    Stack stk;
    while(root != nullptr || !isEmptyStack(stk)){
        if(root != nullptr){
            pushStack(stk,root);
            root = root->lChild;
        }
        else{
            root = peekStack(stk);
            popStack(stk);
            cout << root->data;
            root = root -> rChild;
        }
    }
}

void levelOrder(Tree root){
    if(root == nullptr) return ;
    Queue que; initQueue(que);
    pushQueue(que,root);
    while(!isEmptyQueue(que)){
        Tree temp = getHead(que); popQueue(que);        
        cout << temp->data;
        if(temp->lChild != nullptr) pushQueue(que,temp->lChild);
        if(temp->rChild != nullptr) pushQueue(que,temp->rChild);
    }
}

int leafNode(Tree root){
    if(root->lChild == nullptr && root->rChild == nullptr) return 1;
    int n = leafNode(root->lChild);
    int m = leafNode(root->rChild);
    return n + m;
}

int depth(Tree root){
    int m = depth(root->lChild);
    int n = depth(root->rChild);
    return (m > n ? m : n) + 1;
}

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
	ElementType val = peekStack(stk);
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
    ElementType val = queue.elem[queue.front];
    queue.front = (queue.front + 1) % MAXSIZE;
	return val;
}

ElementType getHead(Queue queue){
    if(!isEmptyQueue(queue))  return queue.elem[queue.front];
}


