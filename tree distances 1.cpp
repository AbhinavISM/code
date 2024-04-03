#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void dfs(vector<vector<int>> &adj, vector<int> &dp,
	int node, int par){
	dp[node] = 0;
	for(int child : adj[node]){
		if(child!=par){
			dfs(adj,dp,child,node);
			dp[node] = max(dp[node], dp[child]+1);
		}
	}
}
 
void reroot(vector<vector<int>> &adj, vector<int> &dp,
	vector<int> &ans, int node, int par){
 
	ans[node-1] = dp[node];
 
	vector<int> pre;
	vector<int> suf;
	for(int child : adj[node]){
		pre.push_back(dp[child]);
		suf.push_back(dp[child]);
	}
	for(int i = 1; i<pre.size(); i++){
		pre[i] = max(pre[i], pre[i-1]);
	}
	for(int i = suf.size()-2; i>=0; i--){
		suf[i] = max(suf[i], suf[i+1]);
	}
 
	int t1 = dp[node];
	int childnum = 0;
	for(int child : adj[node]){
		if(child==par){
			childnum++;
			continue;
		}
		int t2 = dp[child];
 
		int l = -1;
		int r = -1;
		if(childnum-1>=0) l = pre[childnum-1];
		if(childnum+1<suf.size()) r = suf[childnum+1];	
 
		dp[node] = max(l,r) + 1;
		dp[child] = max(dp[child], dp[node]+1);
		reroot(adj,dp,ans,child,node);
 
		dp[node] = t1;
		dp[child] = t2;
		childnum++;
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
	vector<int> ans(n);
 
	dfs(adj,dp,1,-1);
// 	peek(dp)
	reroot(adj,dp,ans,1,-1);
	peek(ans)
	return 0;
}