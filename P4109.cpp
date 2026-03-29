#include<bits/stdc++.h>
using namespace std;
int sum[100001];
const int N = 1000000000;
void pre(){
	sum[1] = 5;
	for(int i = 2;i * 100000 <= N;i++)sum[i] = i * 100000;
};
int calc(int x){
	while(x % 10 == 0){
		x /= 10;
	}
	string s = to_string(x);
	if(x % 10 == 5){
		return s.size() * 2 - 1;
	}
	return s.size() * 2;
}
int main(){
	int q;
	cin >> q;
	pre();
	while(q--){
		int l,r;
		cin >> l >> r;
		int ans = INT_MAX;
		int lsum = ((l - 1) / 100000 + 1),rsum = ((r - 1) / 100000 + 1); 
		if(lsum == rsum){
			for(int i = l;i <= r;i++){
				if(calc(ans) > calc(i)){
					ans = i;
				}
			}
		} 
		else{
			for(int i = l;i <= lsum * 100000;i++){
				if(calc(ans) > calc(i)){
					ans = i;
				}
			}
			for(int i = lsum + 1;i < rsum;i++){
				if(calc(ans) > calc(sum[i])){
					ans = sum[i];
				}
			}
			for(int i = (rsum - 1) * 100000 + 1;i <= r;i++){
				if(calc(ans) > calc(i)){
					ans = i;
				}
			}
		}
		cout << ans << endl;
	}
}
