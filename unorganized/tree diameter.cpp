#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int fans = 0;
pair<int,int> dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
	vis[node] = true;
	int maxi = 0;
	int secmaxi = 0;
	for(int c : adj[node]){
		if(!vis[c]){
			auto it = dfs(c,adj,vis);
			if(it.first+1>maxi){
				secmaxi = maxi;
				maxi = it.first+1;
			} else if(it.first+1>secmaxi){
				secmaxi = it.first+1;
			}
		}
	}
	fans = max(fans, maxi + secmaxi);
	return {maxi, secmaxi};
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
	vector<int> vis(n, false);
	auto ans = dfs(0,adj,vis);
	cout<<fans;
	return 0;
}