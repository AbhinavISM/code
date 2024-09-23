#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void toposort(vector<int> &vis, vector<int> &topo, vector<vector<int>> &adj, int node){
	vis[node] = true;
	for(int child : adj[node]){
		if(!vis[child]){
			toposort(vis,topo,adj,child);
		}
	}
	topo.push_back(node);
}
int32_t main(){
	fast_io;
	int n,m,r;
	cin>>n>>m>>r;
	r--;
	vector<ld> prob(n,0);
	prob[r] = 1.0;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
	}
	vector<int> vis(n,false);
	vector<int> topo;
	toposort(vis,topo,adj,r);
	reverse(topo.begin(), topo.end());
	for(int i = 0; i<topo.size(); i++){
		int node = topo[i];
		for(int child : adj[node]){
			prob[child] += prob[node]/adj[node].size();
		}
	}
	ld maxi = 0;
	for(int i = 0; i<n; i++){
		if(adj[i].size()==0&&prob[i]>=maxi){
			maxi = prob[i];
		}
	}
	vector<int> ans;
	for(int i = 0; i<n; i++){
		if(adj[i].size()==0&&abs(prob[i]-maxi)<=1e-9){
			ans.push_back(i+1);
		}
	}
	peek(ans)
	return 0;
}