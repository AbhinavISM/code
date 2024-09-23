#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
bool topoSort(vector<vector<int>> &adj, vector<int> &vis, vector<int> &topo, int node){
	vis[node] = 1;
	for(int child : adj[node]){
		if(vis[child]==1){
			topo = vector<int>();
			return false;
		}
		if(vis[child]==0){
			bool heh = topoSort(adj,vis,topo,child);
			if(!heh){
				return false;
			}
		}
	}
	topo.push_back(node);
	vis[node] = 2;
	return true;
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
	}
	vector<int> vis(n,0);
	vector<int> topo;
	for(int i = 0; i<n; i++){
		if(vis[i]==0){
			if(!topoSort(adj,vis,topo,i)){
				cout<<"IMPOSSIBLE";
				return 0;
			}
		}
	}
	reverse(topo.begin(), topo.end());
	peek(topo);
}