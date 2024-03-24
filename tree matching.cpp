#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;


void dfs(vector<vector<int>> &adj, vector<vector<int>> &dp, int node, int par){
	if(dp[node][0]!=-1&&dp[node][1]!=-1){
		return;
	}
    for(int child : adj[node]){
        if(child!=par){
            dfs(adj,dp,child,node);
        }
    }
   	dp[node][0] = 0;
    dp[node][1] = 0;
    for(int child : adj[node]){
    	if(child!=par){
    		dp[node][0] += max(dp[child][1], dp[child][0]);
    	}
    }
    
    int sum = dp[node][0];
    for(int child : adj[node]){
    	if(child!=par){
    		dp[node][1] = max(dp[node][1],
    		 sum - max(dp[child][1], dp[child][0]) + dp[child][0] + 1);
    	}
    }
}

int theirdfs(vector<vector<int>> &adj, vector<vector<int>> &dp,
	int node, int par, int uthaya){
	if(dp[node][uthaya]!=-1){
		return dp[node][uthaya];
	}
	dp[node][uthaya] = 0;
	for(int child : adj[node]){
        if(child!=par){
        	dp[node][uthaya] += theirdfs(adj,dp,child,node,0);
        }
    }
	int sum = dp[node][uthaya];
    if(uthaya==0){
    	for(int child : adj[node]){
    		if(child!=par){
    			dp[node][uthaya] = max(dp[node][uthaya],
    			(sum - theirdfs(adj,dp,child,node,0) 
    				+ theirdfs(adj,dp,child,node,1) + 1));
    		}
    	}
    }
    return dp[node][uthaya];
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
	// cout<<max(dp[1][0], dp[1][1]);

	//senior way
	// cout<<max(theirdfs(adj,dp,1,-1,0),theirdfs(adj,dp,1,-1,1));
	// dpeek(dp)
	return 0;
}