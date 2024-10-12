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
		//二叉搜索树的性质为：左子节点 < 根节点 < 右子节点
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
					return ; //二叉搜索树不允许有两个相同值的节点
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
				return ;//说明没有找到
			}
			else{
				if(cur -> left == nullptr || cur -> right == nullptr){
					//代表要删除节点的出度为0或者1
					TreeNode *temp = cur -> left == nullptr ? cur -> right : cur -> left;//这样可以拿到不为空的节点
					if(cur -> val > pre -> val)	pre -> right = temp;
					if(cur -> val < pre -> val) pre -> left = temp;  
				}
				else{
					//代表要删除的节点出度为2
					//应该找到cur节点的左子树最大节点或者右子树的最小节点，之后将找到的节点来替换
					TreeNode *temp = cur -> left;
					while(temp -> right != nullptr){
						temp = temp -> right;
					}
					//此时temp指向左子树最大节点
					int myVal = temp -> val;
					//删除节点
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
