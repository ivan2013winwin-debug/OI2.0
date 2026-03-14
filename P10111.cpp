#include<bits/stdc++.h>
using namespace std;
long long dp[1001][1001][3];
int d[3][3],a[1001],b[1001],c[1001];
long long calc(int x,int y,int k){
	if(d[x][y] == 1){
		return 2 * a[k];
	}
	if(d[x][y] == 0){
		return a[k];
	}
	return 0;
}
int main(){
	d[0][0] = d[1][1] = d[2][2] = 0;
	d[1][0] = d[2][1] = d[0][2] = 1;
	d[0][1] = d[1][2] = d[2][0] = -1;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	for(int i = 1;i < n;i++){
		cin >> b[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[1][0][0] = calc(0,c[1],1);
	dp[1][0][1] = calc(1,c[1],1);
	dp[1][0][2] = calc(2,c[1],1); 
	for(int i = 2;i <= n;i++){
		dp[i][0][0] = dp[i - 1][0][0] + calc(0,c[i],i);
		dp[i][0][1] = dp[i - 1][0][1] + calc(1,c[i],i);
		dp[i][0][2] = dp[i - 1][0][2] + calc(2,c[i],i);
		for(int j = n - 1;j >= 1;j--){
			for(int z = 0;z < 3;z++){
				dp[i][j][z] = dp[i - 1][j][z] + calc(z,c[i],i);
				for(int l = 0;l < 3;l++){
					dp[i][j][z] = max(dp[i][j][z],dp[i - 1][j - 1][l] - b[j] + calc(z,c[i],i));
				}
			}
		}
	} 
	long long ans = 0;
	for(int i = n - 1;i >= 0;i--){
		for(int j = 0;j < 3;j++){
			ans = max(ans,dp[n][i][j]);
		}
	}
	cout << ans;
}
