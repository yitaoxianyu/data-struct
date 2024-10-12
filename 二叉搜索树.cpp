#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};
class BinarySearchTree{
	private:
		TreeNode *root;
	public:
		//����������������Ϊ�����ӽڵ� < ���ڵ� < ���ӽڵ�
		void insert(int val){
			TreeNode *newNode = new TreeNode(val);
			if(root == nullptr){
				root = newNode;
				return ;
			}
			TreeNode *cur = root;
			TreeNode *pre = nullptr;
			while(cur != nullptr){
				if(cur -> val == val){
					return ; //������������������������ֵͬ�Ľڵ�
				}
				pre = cur;
				if(val > cur -> val){
					cur = cur -> right;
				}
				if(val < cur -> val){
					cur = cur -> left;
				}
			}
			if(val > pre -> val) pre -> right = newNode; 	
			if(val < pre -> val) pre -> left = newNode;
		}
		TreeNode *search(int val){
			TreeNode *cur = root;
			while(cur != nullptr){
				if(cur -> val == val) return cur;
				
				if(val > cur -> val) cur = cur -> right;
				if(val < cur -> val) cur = cur -> left;
			}
			return nullptr;
		}
		void remove(int val){
			if(root == nullptr) return ;
			TreeNode *cur = root;
			TreeNode *pre = nullptr;
			while(cur != nullptr){
				if(cur -> val == val){
					return ;
				}
				pre = cur;
				if(val > cur -> val) cur = cur -> right;
				if(val < cur -> val) cur = cur -> left;
			}
			if(cur == nullptr){
				return ;//˵��û���ҵ�
			}
			else{
				if(cur -> left == nullptr || cur -> right == nullptr){
					//����Ҫɾ���ڵ�ĳ���Ϊ0����1
					TreeNode *temp = cur -> left == nullptr ? cur -> right : cur -> left;//���������õ���Ϊ�յĽڵ�
					if(cur -> val > pre -> val)	pre -> right = temp;
					if(cur -> val < pre -> val) pre -> left = temp;  
				}
				else{
					//����Ҫɾ���Ľڵ����Ϊ2
					//Ӧ���ҵ�cur�ڵ�����������ڵ��������������С�ڵ㣬֮���ҵ��Ľڵ����滻
					TreeNode *temp = cur -> left;
					while(temp -> right != nullptr){
						temp = temp -> right;
					}
					//��ʱtempָ�����������ڵ�
					int myVal = temp -> val;
					//ɾ���ڵ�
					remove(myVal);
					cur -> val = val;
				}
			}
		}
};


int main(void)
{
	return 0;
}
