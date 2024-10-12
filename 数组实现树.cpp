#include<bits/stdc++.h>

using namespace std;

class ArrayBinaryTree{
	private:
		vector<int> tree;
		void dfs(vector<int> &res,string order,int i){
			if(i < 0 || i >= size()) return ;
			
			if(order == "pre"){
				res.push_back(val(i));
				dfs(res,"pre",left(i));
				dfs(res,"pre",right(i));	
			}
			
			if(order == "in"){
				dfs(res,"in",left(i));
				res.push_back(val(i));
				dfs(res,"in",right(i));
			}
			
			if(order == "post"){
				dfs(res,"post",left(i));
				dfs(res,"post",right(i));
				res.push_back(val(i));
			}
			
		}
		
		
	public:
		ArrayBinaryTree(vector<int> arr){
			tree = arr;
		}
		int left(int i){
			return 2 * i + 1;
		}
		int right(int i){
			return 2 * i + 2;
		}
		int parent(int i){
			return (i - 1) / 2;
		}
		int size(){
			return tree.size();
		}
		int val(int i){
			if(i < 0 || i >= size()) return INT_MAX;
			//数组对应的空节点用INT_MAX表示
			return tree[i];
		}
		vector<int> bfs(){
			vector<int> res;
			for(int i = 0;i < size();i ++){
				if(val(i) != INT_MAX){
					res.push_back(val(i));
				}
			}
			return res;
		}
		
};


int main(void){
	return 0;
}
