#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void dfs(vector<vector<pair<int,int>>> &adj, vector<int> &vis, int node){
	if(vis[node]==1){
		return;
	}
	vis[node] = 1;
	for(auto child : adj[node]){
		dfs(adj,vis,child.first);
	}
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
	vector<vector<pair<int,int>>> radj(n,vector<pair<int,int>>());
	bool damn = false;
	for(int i = 0; i<m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		if(u==1&&v==1){
			damn = true;
		}
		adj[u-1].push_back({v-1,c});
		radj[v-1].push_back({u-1,c});
	}
	vector<int> cost(n,INT64_MIN);
	cost[0] = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			for(pair<int,int> child : adj[j]){
				int u=j;
				int v=child.first;
				int w=child.second;
				if(cost[u]+w >cost[v])
				{  
				    cost[v]=cost[u]+w;
				}
			}
		}
	}
	vector<int> newCost = cost;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			for(pair<int,int> child : adj[j]){
				int u=j;
				int v=child.first;
				int w=child.second;
				if(newCost[u]==INT64_MAX){
					newCost[v]=INT64_MAX;
				}
				else if(newCost[u]+w >newCost[v])
				{  
				    newCost[v]=INT64_MAX;
				}
			}
		}
	}
	vector<int> vis(n,0);
	vector<int> rvis(n,0);
	dfs(adj,vis,0);
	dfs(radj,rvis,n-1);
	for(int i =0; i<n-1; i++){
		if(vis[i]==1&&rvis[i]==1&&newCost[i]==INT64_MAX){
			damn = true;
		}
	}
	if(((newCost[n-1]==INT64_MAX)&&damn)){
		cout<<"-1";
	} else {
		cout<<cost[n-1];
	}
}