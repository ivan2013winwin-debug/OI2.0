#include<bits/stdc++.h>
using namespace std;
const int N = 10001,M = 100001;
vector<vector<int> >edge(N);
stack<int>st;
vector<int>final[N];
int ans = 1;
int low[N],dfn[N],vis[N],bel[N],f[N];
int sum;
void dfs(int x){
	low[x] = dfn[x] = ++sum;
	vis[x] = true;
	st.push(x);
	for(auto it : edge[x]){
		if(!dfn[it]){
			dfs(it);
			low[x] = min(low[x],low[it]);
		}
		else{
			if(vis[it]){
				low[x] = min(low[x],dfn[it]);
			}
		}
	}
	if(low[x] == dfn[x]){
		ans++;
		while(true){
			int top = st.top();
			st.pop();
			final[ans].push_back(top);
			vis[top] = false;
			bel[top] = ans;
			if(x == top){
				break;
			}
		}
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		edge[u].push_back(v);
	}
	memset(low,0,sizeof(low));
	for(int i = 1;i <= n;i++){
		if(!dfn[i])dfs(i);
	}
	cout << ans - 1 << endl;
	for(int i = 1;i <= ans;i++){
		sort(final[i].begin(),final[i].end());
	}
	for(int i = 1;i <= n;i++){
		if(f[bel[i]]){
			continue;
		}
		f[bel[i]] = 1;
		for(int j = 0;j < final[bel[i]].size();j++){
			cout << final[bel[i]][j] << ' ';
		}
		cout << endl; 
	}
}
