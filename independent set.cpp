#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int mod = 1000000007;
void toposort(vector<bool> &vis, vector<int> &topo, vector<vector<int>> &adj, int node){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            toposort(vis,topo,adj,child);
        }
    }

    topo.push_back(node);
}

void dfs(vector<vector<int>> &adj, vector<vector<int>> &dp, int node, int par){
	if(dp[node][0]!=-1&&dp[node][1]!=-1){
		return;
	}
    for(int child : adj[node]){
        if(child!=par){
            dfs(adj,dp,child,node);
        }
    }
   	dp[node][0] = 1;
    dp[node][1] = 1;
    for(int child : adj[node]){
    	if(child!=par){
    		dp[node][0] = (dp[node][0] * dp[child][1])%mod;
    		dp[node][1] = (dp[node][1] * (dp[child][0] + dp[child][1])%mod)%mod;
    	}
    }
}

int theirdfs(vector<vector<int>> &adj, vector<vector<int>> &dp,
	int node, int par, int color){
	if(dp[node][color]!=-1){
		return dp[node][color];
	}
	dp[node][color] = 1;
	for(int child : adj[node]){
        if(child!=par){
        	if(color==0){
        		dp[node][color] = (dp[node][color]*theirdfs(adj,dp,child,node,1))%mod;
        	} else {
        		dp[node][color] = (dp[node][color]*(theirdfs(adj,dp,child,node,1) 
        							+ theirdfs(adj,dp,child,node,0))%mod)%mod;
        	}
        }
    }
    return dp[node][color];
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
	vector<vector<int>> dp(n+1,vector<int>(2,-1));

	//my way
	// dfs(adj,dp,1,-1);
	// cout<<(dp[1][0] + dp[1][1])%mod<<"\n";

	//senior way
	// cout<<(theirdfs(adj,dp,1,-1,0) + theirdfs(adj,dp,1,-1,1))%mod;
	return 0;
}