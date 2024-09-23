#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void dfs(vector<vector<int>> &adj, vector<int> &dp, vector<int> &a,
	int node, int par){
	dp[node] = a[node];
	for(int child : adj[node]){
		if(child!=par){
			dfs(adj,dp,a,child,node);
			dp[node] += dp[child];
		}
	}
}

void xdfs(vector<vector<int>> &adj, vector<int> &xdp, vector<int> &a,
	int node, int par){
	xdp[node] = a[node];
	for(int child : adj[node]){
		if(child!=par){
			dfs(adj,xdp,a,child,node);
			xdp[node] += xdp[child];
		}
	}
}

void reroot(vector<vector<int>> &adj, vector<int> &dp, vector<int> &a,
	vector<int> &xdp, vector<int> &xa,
	int &ans, int node, int par, int sum){

	int t1 = dp[node];
	int t3 = xdp[node];
	for(int child : adj[node]){
		if(child!=par){
			int t2 = dp[child];
			int t4 = xdp[child];
			//rerooting logic
			dp[node] -= (dp[child]);
			dp[child] += (dp[node]);
			xdp[node] -= (xdp[child]);
			xdp[child] += (xdp[node]);
			int t = sum;
			t -= dp[node];
			t += xdp[node];
			ans = max(ans, t);
			t = sum;
			t -= dp[child];
			t += xdp[child];
			ans = max(ans, t);

			reroot(adj,dp,a,xdp,xa,ans,child,node,sum);

			//restoring original root
			dp[node] = t1;
			dp[child] = t2;
			xdp[node] = t3;
			xdp[child] = t4;
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
	vector<int> a(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	vector<int> xa(n+1,0);
	for(int i = 1; i<=n; i++){
		xa[i] = a[i]^k;
	}
	vector<int> dp(n+1,0);
	dfs(adj,dp,a,1,-1);

	vector<int> xdp(n+1,0);
	xdfs(adj,xdp,xa,1,-1);
	int sum = dp[1];
	int ans = dp[1];
	for(int i = 1; i<=n; i++){
		int t = sum;
		t -= dp[i];
		t += xdp[i];
		ans = max(ans, t);
	}
	reroot(adj,dp,a,xdp,xa,ans,1,-1,sum);
	cout<<ans;
	return 0;
}