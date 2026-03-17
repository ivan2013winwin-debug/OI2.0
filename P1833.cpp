#include<bits/stdc++.h>
using namespace std;
int calc(string T,string T2){
	int h = 0;
	for(int i = 0;T[i] != ':';i++){
		h = h * 10 + T[i] - '0';
	}
	int h2 = 0;
	for(int i = 0;T2[i] != ':';i++){
		h2 = h2 * 10 + T2[i] - '0';
	}
	int m = (T[T.size() - 1] - '0') + (T[T.size() - 2] - '0') * 10;
	int m2 = (T2[T2.size() - 1] - '0') + (T2[T2.size() - 2] - '0') * 10;
	int ans = h2 * 60 - h * 60 - m + m2;
	return ans;
}
vector<int>d(1001);
int main(){
	string T,T2;
	cin >> T >> T2;
	int len = calc(T,T2);
	int n;
	cin >> n;
	vector<int>c(n),p(n),t(n);
	for(int i = 0;i < n;i++){
		cin >> t[i] >> c[i] >> p[i];
	}
	vector<int>dp(len + 1,0);
	dp[0] = 0;
	for(int i = 0;i < n;i++){
		if(p[i] == 0){
			for(int j = t[i];j <= len;j++){
				dp[j] = max(dp[j],dp[j - t[i]] + c[i]);
			}
		}
		else{
			int sum = 0;
			for(int j = 1;j <= p[i];j *= 2){
				d[sum] = j;
				p[i] -= j;
				sum++;
			}
			if(p[i] > 0)d[sum++] = p[i];
			for(int j = 0;j < sum;j++){
				for(int k = len;k >= d[j] * t[i];k--){
					dp[k] = max(dp[k],dp[k - t[i] * d[j]] + c[i] * d[j]);
				}
			}
		}
	} 
	int mx = 0;
	for(int i = 0;i <= len;i++){
		mx = max(mx,dp[i]);
	}
	cout << mx;
}

