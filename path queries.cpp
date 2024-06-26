#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int dfs(vector<vector<int>> &adj, int node, int n, vector<int> &sz,
 vector<bool> &vis, vector<int> &dfs_sequence){
	vis[node] = true;
	dfs_sequence.push_back(node);
	int size = 1;
	for(int child : adj[node]){
		if(!vis[child]) size += dfs(adj, child, n, sz, vis, dfs_sequence);
	}
	return sz[node] = size;
}
void update(vector<int> &BIT, int idx, int val, int n){
	while(idx<=n){
		BIT[idx] += val;
		idx += ((idx)&(-idx));
	}
}
int prefix(vector<int> &BIT, int idx){
	int ans = 0;
	while(idx>0){
		ans += BIT[idx];
		idx -= ((idx)&(-idx));
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int t;
	cin>>t;
	vector<int> a(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i = 1; i<=n-1; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> sz(n+1,0);
	vector<bool> vis(n+1, false);
	vector<int> dfs_sequence;
	dfs_sequence.push_back(0);
	dfs(adj, 1, n, sz ,vis, dfs_sequence);

	vector<int> BIT(n+1, 0);
	vector<int> dfs_pos(n+1,0);
	for(int i = 1; i<=n; i++){
		dfs_pos[dfs_sequence[i]] = i;
		update(BIT, i, a[dfs_sequence[i]], n);
		update(BIT, i+sz[dfs_sequence[i]], -a[dfs_sequence[i]], n);
	}

	while(t--){
	int q;
	cin>>q;
	if(q==1) {
		int s,x;
		cin>>s>>x;
		update(BIT, dfs_pos[s], x-a[s], n);
		update(BIT, dfs_pos[s] + sz[s], -1*(x-a[s]), n);
		a[s] = x;
	} else {
		int s;
		cin>>s;
		cout<<prefix(BIT, dfs_pos[s])<<"\n";
	}
}
	return 0;
}