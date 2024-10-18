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

bool dfs(int node, int par, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path){
	vis[node] = 1;
	path.push_back(node);
	for(int child : adj[node]){
		if(vis[child]==1&&child!=par) {
			path.push_back(child);
			return true;
		} else if(vis[child]==0){
			if(dfs(child, node, adj, vis, path)) return true;
		}
	}
	vis[node] = 2;
	return false;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> adj(n, vector<int>());
		bool good = true;
		for(int i=0; i<n; i++){
			int u,v;
			cin>>u>>v;
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
			if(adj[u-1].size()>=3||adj[v-1].size()>=3||u==v) good = false;
		}
		if(!good){
			cout<<"NO\n";
			continue;
		}
		vector<int> vis(n, 0);
		for(int node=0; node<n; node++){
			vector<int> path;
			if(vis[node]==0){
				if(dfs(node, -1, adj, vis, path)){
					for(int i=0; i<path.size(); i++){
						if(path[i]==path.back()) {
							int cycleSize = path.size() - i - 1;
							if(cycleSize%2) good = false;
						}
					}
				}
			}
		}
		if(good) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
