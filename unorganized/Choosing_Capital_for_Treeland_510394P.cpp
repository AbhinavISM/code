#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

void dfs(vector<vector<pii>> &adj, vector<bool> &vis, vector<int> &dp, int node){
	vis[node] = true;
	for(auto e : adj[node]){
		int child = e.first;
		int red = e.second;
		if(!vis[child]) {
            dfs(adj,vis,dp,child);
            dp[node]+=dp[child];
            if(red==1) {dp[node]++;}
		}
	}
}

int reroot(vector<vector<pii>> &adj, vector<int> &dp, vector<int> &ans,
 int node, int par){
 	ans[node] = dp[node];

 	int t1 = dp[node];
 	for(auto e : adj[node]){
 		int child = e.first;
 		int red = e.second;
 		int t2 = dp[child];
 		if(child==par){continue;}

 		dp[node] -= dp[child];
 		if(red==1) dp[node] -= (1);
 		if(red==1) dp[child] += (dp[node]);
 		else dp[child] += (dp[node]+1);
 		reroot(adj,dp,ans,child,node);

 		dp[node] = t1;
 		dp[child] = t2;
 	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> dp(n,0);
	vector<vector<pii>> adj(n,vector<pii>());
	for(int i = 0; i<n-1; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back({v-1,0});
		adj[v-1].push_back({u-1,1});
	}
	vector<bool> vis(n,false);
	dfs(adj,vis,dp,0);
	vector<int> ans(n);
	// peek(dp)
	reroot(adj,dp,ans,0,-1);
	// peek(ans)
	int mini = INT_MAX;
	for(int i = 0; i<n; i++){
		mini = min(mini, ans[i]);
	}
	vector<int> fans;
	for(int i = 0; i<n; i++){
		if(mini==ans[i]) fans.push_back(i+1);
	}
	cout<<mini<<"\n";
	peek(fans)
}