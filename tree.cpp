#include "Tree.h"
#include<bits/stdc++.h>

using namespace std;

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
    stack<Tree> stk;
    while(root != nullptr || !stk.empty()){
        if(root != nullptr){
            stk.push(root);
            root = root->lChild;
        }
        else{
            root = stk.top();stk.pop();
            cout << root->data;
            root = root -> rChild;
        }
    }
}

void levelOrder(Tree root){
    if(root == nullptr) return ;
    queue<Tree> que;
    que.push(root);
    while(!que.empty()){
        Tree temp = que.front(); que.pop();        
        cout << temp->data;
        if(temp->lChild != nullptr) que.push(temp->lChild);
        if(temp->rChild != nullptr) que.push(temp->rChild);
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

int main(void){
    Tree tree = nullptr;
    createTree(tree);
    preOrder(tree);
    return 0;
}