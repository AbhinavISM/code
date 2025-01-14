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

void solve(int n, int m, vector<vector<pair<int, int>>> &adj, int a, int b, int k, vector<bool> &vis, vector<int> &pathwts, vector<vector<int>> &allpathwts){
	vis[a] = true;
	for(auto it : adj[a]){
		int child = it.first;
		int cost = it.second;
		if(!vis[child]){
			if(child==b){
				pathwts.push_back(cost);
				allpathwts.push_back(pathwts);
				pathwts.pop_back();
			} else {
				pathwts.push_back(cost);
				solve(n,m,adj,child,b,k,vis,pathwts,allpathwts);
				pathwts.pop_back();
			}
		}
	}
	vis[a] = false;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,m,q;
		cin>>n>>m>>q;
		vector<vector<pair<int, int>>> adj(n,vector<pair<int, int>>());
		for(int i = 0; i<m; i++){
			int u,v,w;
			cin>>u>>v>>w;
			u--; v--; w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		while(q--){
			int a,b,k;
			cin>>a>>b>>k;
			a--; b--; k--;
			vector<bool> vis(n, false);
			vector<vector<int>> allpathwts;
			vector<int> pathwts;
			solve(n,m,adj,a,b,k,vis,pathwts,allpathwts);
			int ans = INT64_MAX;
			for(auto it : allpathwts){
				sort(it.begin(), it.end(), greater<int>());
				if(k<it.size()) ans = min(ans, it[k]);
			}
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
	return 0;
}