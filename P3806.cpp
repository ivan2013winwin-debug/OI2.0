#include<bits/stdc++.h>
using namespace std;
const int N = 10001;
struct node{
	int v,w;
	node(int x,int y){
		v = x,w = y;
	}
};
vector<node>edge[N];
int n,m,k;
int heart,f[N],mn;
bool ans,vis[N];
void find(int x,int fa,int nn){
	int mx = 0;
	f[x] = 1;
	for(int i = 0;i < edge[x].size();i++){
		int v = edge[x][i].v,w = edge[x][i].w;
		if(v != fa && !vis[v]){
			find(v,x,nn);
			f[x] += f[v];
			mx = max(mx,f[v]);
		}
	}
	mx = max(mx,nn - f[x]);
	if(mx < mn){
		mn = mx;
		heart = x;
	}
}
void dfs(int x,int fa,int dep,vector<int>&dist){
	if(dep > k)return;
	dist.push_back(dep);
	for(int i = 0;i < edge[x].size();i++){
		int v = edge[x][i].v,w = edge[x][i].w;
		if(v != fa && !vis[v]){
			dfs(v,x,dep + w,dist);
		}
	}
}
void solve(int x){
	if(ans)return;
	vis[x] = true;
	unordered_set<int>seen;
	seen.insert(0);
	for(int i = 0;i < edge[x].size();i++){
		int v = edge[x][i].v,w = edge[x][i].w;
		if(!vis[v]){
			vector<int>dist;
			dfs(v,x,w,dist);
			for(int j = 0;j < dist.size();j++){
				if(seen.count(k - dist[j])){
					ans = true;
					return;
				}
			}
			for(int j = 0;j < dist.size();j++){
			seen.insert(dist[j]);
			}
		}
	}
	for(int i = 0;i < edge[x].size();i++){
		int v = edge[x][i].v,w = edge[x][i].w;
		if(!vis[v]){
			mn = INT_MAX;
			find(v,x,f[v]);
			solve(heart);
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edge[u].push_back(node(v,w));
		edge[v].push_back(node(u,w));
	}
	while(m--){
		cin >> k;
		mn = INT_MAX;
		ans = false;
		memset(vis,false,sizeof(vis));
		find(1,-1,n);
		solve(heart);
		if(ans){
			cout << "AYE" << endl;
		}
		else{
			cout << "NAY" << endl;
		}
	}
} 
