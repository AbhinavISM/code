#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void fillSparse(vector<vector<int>> &adj, vector<vector<int>> &sparse, vector<int> &par, vector<bool> &vis, int &n, int i){
	if(i!=0){
		sparse[i][0] = par[i];
		for(int j = 1; j<20; j++){
			if(sparse[i][j-1]!=-1) sparse[i][j] = sparse[sparse[i][j-1]][j-1];
			else sparse[i][j-1] = -1;
		}
	}
	vis[i] = true;
	for(int child : adj[i]){
		if(!vis[child]) fillSparse(adj,sparse,par,vis,n,child);
	}
}
void dfs(vector<vector<int>> &adj, vector<bool> &vis, int node, vector<int> &par, vector<int> &levels, int lvl){
	vis[node] = true;
	levels[node] = lvl;
	for(int child : adj[node]){
		if(!vis[child]) {
			par[child] = node;
			dfs(adj, vis, child, par, levels, lvl+1);
		}
	}
}
int binLift(int a, int x, vector<vector<int>> &sparse){
	for(int i = 0; i<20; i++){
		if(x&(1<<i)) a = sparse[a][i];
		if(a==-1) break;
	}
	return a;
}
int lca(int a, int b, vector<vector<int>> &sparse, vector<int> &levels){
	if(levels[a]>=levels[b]){
		a = binLift(a,levels[a]-levels[b], sparse);
	} else {
		b = binLift(b,levels[b]-levels[a], sparse);
	}
	if(a==b) return a;
	for(int i = 19; i>=0; i--){
		if(sparse[a][i]!=sparse[b][i]){
			a = sparse[a][i];
			b = sparse[b][i];
		}
	}
	return sparse[a][0];
}
int32_t main(){
	fast_io;
	int n,q;
	cin>>n>>q;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<n-1; i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u-1].push_back(v-1);
	    adj[v-1].push_back(u-1);
	}

	vector<bool> vis(n, false);
	vector<int> par(n, -1);
	vector<int> levels(n, 0);
	dfs(adj, vis, 0, par, levels, 0);

	vis = vector<bool>(n, false);
	vector<vector<int>> sparse(n,vector<int>(20,-1));
	fillSparse(adj, sparse, par, vis, n, 0);
	while(q--){
		int a,b;
		cin>>a>>b;
		a--;b--;
		cout<<levels[a]+levels[b]-2*levels[lca(a,b,sparse,levels)]<<"\n";
	}
	return 0;
}
