#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void dfs(vector<vector<int>> &adj, vector<int> &dp, vector<int> &sz,
	int node, int par){
	dp[node] = 0;
	sz[node] = 1;
	for(int child : adj[node]){
		if(child!=par){
			dfs(adj,dp,sz,child,node);
			dp[node] += dp[child] + sz[child];
			sz[node] += sz[child];
		}
	}
}

void reroot(vector<vector<int>> &adj, vector<int> &dp, vector<int> &sz,
	vector<int> &ans, int node, int par){
	//putting in node-1 just because ans array is 0 based,
	//unlike other arrays
	ans[node-1] = dp[node];

	int t1 = dp[node];
	int s1 = sz[node];
	for(int child : adj[node]){
		if(child!=par){
			int t2 = dp[child];
			int s2 = sz[child];

			//rerooting logic
			sz[node] -= (sz[child]);
			dp[node] -= (sz[child] + dp[child]);

			sz[child] += (sz[node]);
			dp[child] += (dp[node] + sz[node]);

			reroot(adj,dp,sz,ans,child,node);

			//restoring original root
			dp[node] = t1;
			sz[node] = s1;
			dp[child] = t2;
			sz[child] = s2;
		}
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i = 2; i<=n; i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	vector<int> dp(n+1,0);
	vector<int> sz(n+1,0);
	vector<int> ans(n);

	dfs(adj,dp,sz,1,-1);
	reroot(adj,dp,sz,ans,1,-1);
	peek(ans)
	return 0;
}