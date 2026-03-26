#include<bits/stdc++.h>
using namespace std;
const int N = 16001;
vector<vector<int> >edge(N);
bool b[N];
int mn,f[N],n;
vector<int>final;
void dfs(int x,int fa){
	int ans = 0;
	f[x] = 1;
	b[x] = true;
	for(int i = 0;i < edge[x].size();i++){
		int it = edge[x][i];
		if(b[it])continue;
		b[it] = true;
		dfs(it,x);
		f[x] += f[it];
		ans = max(ans,f[it]);
	}
	ans = max(ans,n - f[x]);
	if(ans < mn){
		mn = ans;
		final.clear();
	}
	if(ans == mn){
		final.push_back(x);
	}
}
int main(){
	cin >> n;
	for(int i = 1;i < n;i++){
		int a,b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	mn = INT_MAX;
	memset(b,false,sizeof(b));
	memset(f,0,sizeof(f));
	dfs(1,-1);
	sort(final.begin(),final.end());
	cout << mn << ' ' << final.size() << endl;
	for(int i = 0;i < final.size();i++){
		cout << final[i] << ' '; 
	} 
} 
