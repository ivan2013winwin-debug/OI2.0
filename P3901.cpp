#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,id;
};
int n,q,block,sum;
int a[100001];
node ans[100001];
int b[100001];
bool cmp(node a,node b){
	int ax = a.l / block + 1,bx = b.l / block + 1;
	if(ax == bx){
		return a.r < b.r;
	}
	return ax < bx;
}
void add(int x){
	if(b[x] == 0){
		sum++;
	}
	b[x]++;
}
void reduce(int x){
	b[x]--;
	if(b[x] <= 0){
		sum--;
	}
}
int main(){
	cin >> n >> q;
	block = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	for(int i = 0;i < q;i++){
		cin >> ans[i].l >> ans[i].r;
		ans[i].id = i;
	}
	sort(ans,ans + q,cmp);
	int l = 1,r = 0;
	sum = 0;
	vector<int>final(q);
	memset(b,0,sizeof(b));
	for(int i = 0;i < q;i++){
		while(l > ans[i].l){
			l--;
			add(a[l]);
		}
		while(r < ans[i].r){
			r++;
			add(a[r]);
		}
		while(l < ans[i].l){
			reduce(a[l]);
			l++;
		}
		while(r > ans[i].r){
			reduce(a[r]);
			r--;
		}
		final[ans[i].id] = sum - (ans[i].r - ans[i].l + 1);
	}
	for(int i = 0;i < q;i++){
		if(final[i] >= 0)cout << "Yes" << endl;
		else{
			cout << "No" << endl;
		}
	}
} 
