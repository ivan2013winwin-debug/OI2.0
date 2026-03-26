#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
struct node{
	int v,w;
	node(int x,int y){
		v = x,w = y;
	}
};
int n,k,sum;
vector<node>edge[N];
int heart,mn,f[N];
bool vis[N];
void find(int x,int fa,int nn){
	int mx = 0;
	f[x] = 1;
	for(int i = 0;i < edge[x].size();i++){
		int it = edge[x][i].v;
		if(it != fa && !vis[it]){
			find(it,x,nn);
			f[x] += f[it];
			mx = max(mx,f[it]);
		}
	}
	mx = max(mx,nn - f[x]);
	if(mx < mn){
		mn = mx;
		heart = x;
	}
}
int dist[N],cnt;
void dfs(int x,int fa,int dep){
	dist[++cnt] = dep;
	for(int i = 0;i < edge[x].size();i++){
		int v = edge[x][i].v,w = edge[x][i].w;
		if(v != fa && !vis[v]){
			dfs(v,x,dep + w);
		}
	}
}
int calc(int x,int t){
	cnt = 0;
	dfs(x,-1,t);
	sort(dist + 1,dist + cnt + 1);
	int left = 1,right = cnt,ans = 0;
	while(left < right){
		if(dist[left] + dist[right] <= k){
			ans += (right - left);
			left++;
		}
		else{
			right--;
		}
	} 
	return ans;
}
void solve(int x){
	vis[x] = true;
	sum += calc(x,0);
	for(int i = 0;i < edge[x].size();i++){
		int v = edge[x][i].v,w = edge[x][i].w;
		if(!vis[v]){
			sum -= calc(v,w);
			heart = 0;
			mn = INT_MAX;
			find(v,-1,f[v]);
			solve(heart);
		}
	}
}
int main(){
	while(true){
		cin >> n >> k;
		if(n == 0 && k == 0)return 0;
		for(int i = 1;i < n;i++){
			int u,v,l;
			cin >> u >> v >> l;
			edge[u].push_back(node(v,l));
			edge[v].push_back(node(u,l)); 
		}
		mn = INT_MAX;
		memset(vis,0,sizeof(vis));
		find(1,-1,n);
		sum = 0;
		solve(heart);
		cout << sum << endl;
		for(int i = 1;i <= n;i++){
			edge[i].clear();
		}
	}
} 
