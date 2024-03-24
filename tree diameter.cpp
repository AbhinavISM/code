#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void dfs(int n, vector<vector<int>> &adj, vector<int> &dis){
	for(int c : adj[n]){
		if(dis[c]==INT_MAX){
			dis[c] = dis[n] + 1;
			dfs(c,adj,dis);
		}
	}
}
int tree_diameter(int n, vector<vector<int>> &adj){
	vector<int> dis(n,INT_MAX);
	dis[0] = 0;
	dfs(0,adj,dis);
	
	int newsrc;
	int maxdis = 0;
	for(int i = 0; i<n; i++){
		maxdis = max(maxdis, dis[i]);
		if(maxdis==dis[i]){
			newsrc = i;
		}
	}

	dis = vector<int>(n,INT_MAX);
	dis[newsrc] = 0;
	dfs(newsrc,adj,dis);
	
	int diam = 0;
	for(int i = 0; i<n; i++){
		diam = max(diam, dis[i]);
	}
	return diam;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<n-1; i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u-1].push_back(v-1);
	    adj[v-1].push_back(u-1);
	}
	cout<<tree_diameter(n,adj);
	return 0;
}