#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int dfs(int node, int par, vector<int> &dp, vector<vector<int>> &adj){
	dp[node] = 1;
	for(int child : adj[node]){
		if(child!=par){
			dp[node]+=dfs(child, node, dp, adj);
		}
	}
	return dp[node];
}
void reroot(int node, int par, vector<char> &type, multiset<int> &minr, vector<int> &ans, vector<int> &dp, vector<vector<int>> &adj){
	ans[node] = dp[node] - *minr.begin();
	int t1 = dp[node];
	for(int child : adj[node]){
		if(child==par) continue;
		int t2 = dp[child];

		if(type[node]=='R') minr.erase(minr.find(dp[node]));
		if(type[child]=='R') minr.erase(minr.find(dp[child]));
		dp[node] -= dp[child];
		dp[child] += dp[node];
		if(type[node]=='R') minr.insert(dp[node]);
		if(type[child]=='R') minr.insert(dp[child]);

		reroot(child, node, type, minr, ans, dp, adj);

		if(type[node]=='R') minr.erase(minr.find(dp[node]));
		if(type[child]=='R') minr.erase(minr.find(dp[child]));
		dp[node] = t1;
		dp[child] = t2;
		if(type[node]=='R') minr.insert(dp[node]);
		if(type[child]=='R') minr.insert(dp[child]);
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<n-1; i++){
		int city; cin>>city; city--;
		adj[i+1].push_back(city);
		adj[city].push_back(i+1);
	}
	vector<char> type(n);
	int rcnt = 0;
	for(int i = 0; i<n; i++){
		cin>>type[i];
		if(type[i]=='R') rcnt++;
	}
	vector<int> dp(n,0);
	dfs(0,-1,dp,adj);

	if(rcnt%2==0){
		cout<<dp[0]*n;
		return 0;
	}

	multiset<int> minr;
	for(int i = 0; i<n; i++){
		if(type[i]=='R') minr.insert(dp[i]);
	}
	vector<int> ans(n);
	reroot(0, -1, type, minr, ans, dp, adj);
	cout<< accumulate(ans.begin(), ans.end(), 0);
}