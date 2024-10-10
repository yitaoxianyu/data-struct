#include<bits/stdc++.h>
using ll = long long;
using namespace std;


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	vector<int> nums = {1, 5, 2, 3, 6, 2, 2, 7, 2};
	
	int slow = 0 , fast = 0;
	int target = 2;
	
	while(fast != (int)nums.size()){
		if(nums[slow] == target && nums[fast] == target){
			fast ++;
			continue;
		}
		if(nums[slow] == target && nums[fast] != target){
			int temp = nums[slow];
			nums[slow] = nums[fast];
			nums[fast] = temp;
		}
		slow ++;
		fast ++;
	}
	
	for(int i = 0;i < slow;i ++) cout << nums[i];
	
	return 0;
}
