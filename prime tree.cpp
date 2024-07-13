#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

ll mod = 1000000007;
void dfs(ll node, ll par, vector<vector<ll>> &adj, vector<vector<ll>> &dp, ll a, ll b){
	dp[node][0] = 1;
	dp[node][1] = a;
	dp[node][2] = b;
	for(ll child : adj[node]){
		if(child!=par) {
			dfs(child, node, adj, dp, a, b);
			dp[node][0] = (dp[node][0]*(dp[child][0] + dp[child][1])%mod)%mod;
			dp[node][1] = (dp[node][1]*(dp[child][0] + dp[child][1] + dp[child][2])%mod)%mod;
			dp[node][2] = (dp[node][2]*(dp[child][1] + dp[child][2])%mod)%mod;
		}
	}
}
int main(){
	fast_io;
	ll a = 0; ll b = 0;
	for(ll j = 3; j<=100; j++){
		ll jprime = true;
		for(ll d = 2; d*d<=j; d++){
			if(j%d==0) jprime = false;
		}
		if(jprime){
			ll sum = 2+j;
			ll sumprime = true;
			for(ll d = 2; d*d<=sum; d++){
				if(sum%d==0) sumprime = false;
			}
			if(sumprime) b++;
			else a++;
		}
	}
	ll t;
	cin>>t;
	while(t--){
	ll n;
	cin>>n;
	vector<vector<ll>> adj(n,vector<ll>());
	for(ll i = 0; i<n-1; i++){
		ll u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<ll>> dp(n, vector<ll>(3,0));
	dfs(0,-1,adj,dp,a,b);
	cout<<dp[0][0] + dp[0][1] + dp[0][2]<<"\n";
}
	return 0;
}