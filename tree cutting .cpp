#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int dfs(vector<vector<int>> &adj, int node, int par, int &mid, int &cmp, vector<int> &dp){
    int tominus = 0;
    for(int child : adj[node]){
        if(child!=par){
            tominus += dfs(adj,child,node,mid,cmp,dp);
        }
    }
    if(dp[node]-tominus>=mid){
    	cmp++;
    	return dp[node];
    } else {
    	return tominus;
    }
}
void dfsdp(vector<vector<int>> &adj, int node, int par, vector<int> &dp){
    for(int child : adj[node]){
        if(par!=child){
            dfsdp(adj,child,node,dp);
            dp[node] += dp[child];
        }
    }
}


int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<n-1; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	int lo = 1;
	int hi = n;
	int ans = 1;
	vector<int> dp(n,1);
	dfsdp(adj,0,0,dp);
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int cmp = 0;
		dfs(adj,0,0,mid,cmp,dp);
		if(cmp>=k+1){
			lo = mid + 1;
			ans = max(ans,mid);
		} else {
			hi = mid - 1;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}