#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set
void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &lvl){
	for(int child : adj[node]){
		if(child!=par) {
			lvl[child] = lvl[node] + 1;
			dfs(child, node, adj, lvl);
		}
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,s,e;
		cin>>n>>s>>e;
		s--; e--;
		vector<vector<int>> adj(n,vector<int>());
		for(int i = 0; i<n-1; i++){
			int u,v;
			cin>>u>>v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> lvl(n, -1);
		lvl[e] = 0;
		dfs(e,-1,adj,lvl);
		vector<vector<int>> seq(n, vector<int>());
		for(int i = 0; i<n; i++){
			seq[lvl[i]].push_back(i);
		}
		reverse(seq.begin(), seq.end());
		for(vector<int> v : seq){
			for(int e : v){
				cout<<e+1<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}