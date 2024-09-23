#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i : v) {for(auto j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
bool dfs(vector<vector<bool>> &adj, vector<int> &vis, int node,int color){
	vis[node] = color;
	for(int i = 0; i<adj[node].size(); i++){
		if((!adj[node][i])||i==node){
			continue;
		}
		int child = i;
		if(vis[child]==vis[node]){
			return false;
		}
		if(vis[child]==0){
			bool heh = dfs(adj,vis,child,3-color);
			if(!heh){
				return false;
			}
		}
	}
	return true;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	vector<vector<bool>> adj(n,vector<bool>(n,1));
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1][v-1] = 0;
		adj[v-1][u-1] = 0;
	}
	vector<int> vis(n,0);
	bool ans = true;
	for(int i = 0; i<n; i++){
		if(vis[i]==0){
			if(!dfs(adj,vis,i,1)){
				ans = false;
				break;
			}
		}
	}
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
	}
}