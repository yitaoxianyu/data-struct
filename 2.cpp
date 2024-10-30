#include<bits/stdc++.h>

using namespace std;

int main(void){
	int T; cin >> T;
	while(T--){
		int n, ans = 0;cin >> n; //1µ½n
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= i;j ++){
				if(n % j == 0) ans ++;
			}
		}
		cout << ans;
	}
	
	
	return 0;
}
