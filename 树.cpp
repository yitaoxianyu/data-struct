#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};

//二叉树的层序遍历bfs
vector<int> levelOreder(TreeNode *root){
	queue<TreeNode *>queue;	queue.push(root);
	vector<int> vec;
	while(queue.size()){
		TreeNode *temp = queue.front();
		vec.push_back(temp->val);
		queue.pop();
		if(temp->left) queue.push(temp->left); 
		if(temp->right) queue.push(temp->right);
	}
	return vec;
}
//二叉树dfs
void preOrder(TreeNode *root){
	//前序遍历，根左右
	if(!root){
		return ;
	}
	
	cout << root->val << endl;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode *root){
	//中序遍历，左根右
	if(!root){
		return ;
	}
	inOrder(root->left);
	cout << root->val << endl;
	inOrder(root->right);
}

void postOrder(TreeNode *root){
	//后序遍历左右根
	if(!root){
		return ;
	}
	
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << endl;
}

int main(void){
	
	
	
	return 0;
}
