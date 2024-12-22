#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set

bool dfs(vector<vector<int>> &adj, vector<int> &vis, int &cyclic, int node){
	vis[node] = 1;
	for(int child : adj[node]){
		if(vis[child]==vis[node]){
			cyclic = child;
			vis[node] = 2;
			return true;
		}
		if(vis[child]==0){
			if(dfs(adj,vis,cyclic,child)){
				vis[node] = 2;
				return true;
			}
		}
	}
	vis[node] = 2;
	return false;
}
void dfs2(vector<vector<int>> &adj, bool first, int node, int cyclic, set<int> &allcyclic){
	allcyclic.insert(node);
	for(int child : adj[node]){
		if(child==cyclic&&!first){
			return;
		}
		dfs2(adj, false, child, cyclic, allcyclic);
	}
}
int dfs3(vector<vector<int>> &adj, set<int> &allcyclic, int node, vector<int> &dp){
	if(dp[node]!=-1) return dp[node];
	for(int child : adj[node]){
		if(allcyclic.find(child)==allcyclic.end()){
			return dp[node] = dfs3(adj, allcyclic, child, dp)+1;
		} else {
			return dp[node] = 2;
		}
	}
	return dp[node] = 1;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> adj(n, vector<int>());
		for(int i = 0; i<n; i++){
			int v;
			cin>>v;
			v--;
			adj[i].push_back(v);
		}
		vector<int> vis(n, 0);
		set<int> allcyclic;
		for(int i = 0; i<n; i++){
			int cyclic = -1;
			if(vis[i]==0){
				if(dfs(adj, vis, cyclic, i)){
					dfs2(adj, false, cyclic, cyclic, allcyclic);
				}
			}
		}
		vector<int> dp(n, -1);
		int ans = 2;
		for(int i = 0; i<n; i++){
			if(allcyclic.find(i)==allcyclic.end()){
				ans = max(ans, dfs3(adj, allcyclic, i, dp)+1);	
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}