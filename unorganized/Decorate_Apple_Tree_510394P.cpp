#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

void dfs(vector<vector<int>> &adj, int node, int par, vector<int> &dp, vector<int> &pararr){
	// cout<<node<<" "<<dp[node]<<"\n";
	for(int child : adj[node]){
		if(child==par) {continue;}
		pararr[child] = node;
		dfs(adj,child,node,dp,pararr);
		dp[node] += dp[child];
	}
	// cout<<node<<" "<<dp[node]<<"\n";
}
void make_happy(vector<vector<int>> &adj, int node, int par, vector<bool> &happy){
	happy[node] = true;
	for(int child : adj[node]){
		if(child==par||happy[child]) {continue;}
		make_happy(adj,child,node,happy);
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 1; i<n; i++){
		int p;
		cin>>p;
		adj[i].push_back(p-1);
		adj[p-1].push_back(i);
	}

	vector<int> dp(n,1);
	vector<int> pararr(n,-1);
	dfs(adj,0,-1,dp,pararr);
	// peek(dp) ok
	// peek(pararr) ok

	vector<pii> dps;
	for(int i = 0; i<n; i++){
		dps.push_back({dp[i],i});
	}
	sort(dps.begin(), dps.end());
	for(auto c : dps){
		cout<<c.first<<" "<<c.second<<"\n";
	}
	vector<int> ans(n,INT_MAX);
	for(int k = 1; k<=n; k++){
		int i = 0;
		vector<bool> happy(n,false);
		while(dps[i].first<=k&&i<n){
			if(!happy[dps[i].second])
			make_happy(adj,dps[i].second,pararr[dps[i].second],happy);
			i++;
		}
		int happycnt = 0;
		for(bool haal : happy) {
			if(haal) happycnt++;
		}
		if (k==3) {cout<<happycnt<<"\n";}
		ans[happycnt-1] = min(ans[happycnt-1],k);
	}
	peek(ans)
	for(int i = n-2; i>=0; i--){
		ans[i] = min(ans[i], ans[i+1]);
	}
	// peek(ans)
}