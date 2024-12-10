#include<bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> res;
queue<int> que;

void fn(int rows){
	for(int i = 1;i <= rows;i ++){
		vector<int> row; 
		for(int j = 0;j < i;j ++){
			if(j == 0 || j == i - 1) row.push_back(1);
			else{
				int left = que.front(); que.pop();
				int right = que.front();
				que.push(left + right);
				row.push_back(left + right);
			}
		}
		res.push_back(row);
		que.push(1);
	}
	
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int rows = 0; cin >> rows;
	fn(rows);
	for(auto i : res){
		for(auto j : i){
			cout << j;
		}
		cout << endl;
	}
	return 0;
}
