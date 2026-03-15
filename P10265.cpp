#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int sum1 = 0,sum2 = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			int x;
			cin >> x;
			if(j == m && x){
				sum2++;
			}
			if(i == m && x){
				sum1++;
			}
		}
	} 
	cout << sum1 << ' ' << sum2 << ' ' << sum1 + sum2;
}
