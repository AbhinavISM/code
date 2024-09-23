#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int dfs(vector<vector<int>> &adj, int node, int par, vector<int> &dp){
    int ans = 0;
    for(int child : adj[node]){
        if(par!=child){
            ans += dfs(adj,child,node,dp);
            dp[node] += dp[child];
        }
    }
    if(dp[node]%2){
    	return ans;
    } else {
    	return ans + 1;
    }
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
	if(n%2){
		cout<<-1<<"\n";
		return 0;
	}
	vector<int> dp(n,1);
	cout<<dfs(adj,0,0,dp)-1<<"\n";
	return 0;
}