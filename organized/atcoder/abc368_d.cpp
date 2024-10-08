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

int dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, set<int> &s, int &ans){
	vis[node] = true;
	int cnt = 0;
	for(int child : adj[node]){
		if(!vis[child]) cnt += dfs(child, vis, adj, s, ans);
	}
	if(s.find(node)!=s.end()) cnt++;
	if(cnt!=0) ans++;
	return cnt;
}
int32_t main(){
	fast_io;
	int t;
	t = 1;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int>> adj(n);
		for(int i = 0; i<n-1; i++){
			int u,v; cin>>u>>v; u--;v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		set<int> s;
		for(int i = 0; i<k; i++){
			int must; cin>>must; must--;
			s.insert(must);
		}
		vector<bool> vis(n, false);
		int ans = 0;
		dfs(*(s.begin()), vis, adj, s, ans);
		cout<<ans;
	}
	return 0;
}