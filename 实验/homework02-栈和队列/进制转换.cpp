#include<bits/stdc++.h>

using namespace std;

void fn(int number,int n){
	if(!number) return ;
	fn(number / n,n);
	cout << number % n;
}

int main(void){
	int n; cin >> n;
	int number; cin >> number;
	fn(number,n);
}
