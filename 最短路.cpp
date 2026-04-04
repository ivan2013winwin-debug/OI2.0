#include<bits/stdc++.h>
using namespace std;
const int N = 110,inf = 1e7;
int dist[N][N],d[N];
bool vis[N];
int main(){
	int n,m;
	while(cin >> n >> m){
		if(n == 0 && m == 0)return 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j)dist[i][j] = 0;
				else{
					dist[i][j] = inf;
				}
			}
		}
		for(int i = 0;i < m;i++){
			int a,b,c;
			cin >> a >> b >> c;
			dist[a][b] = dist[b][a] = min(dist[a][b],c);
		}
		fill(d + 1,d + n + 1,inf);
		fill(vis + 1,vis + n + 1,false);
		d[1] = 0;
		for(int i = 1;i <= n;i++){
			int t = -1,mn = inf;
			for(int j = 1;j <= n;j++){
				if(!vis[j] && d[j] < mn){
					mn = d[j];
					t = j;
				}
			}	
			if(t == -1)break;
			vis[t] = true;
			for(int j = 1;j <= n;j++){
				if(!vis[j] && dist[t][j] != inf){
					if(d[j] > d[t] + dist[t][j]){
						d[j] = d[t] + dist[t][j];
					}
				}
			}
		}
		cout << d[n] << endl;
	}
}
