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
void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &lvl){
	if(par==-1) lvl[node] = 0;
	else lvl[node] = lvl[par] + 1;
	for(int child : adj[node]){
		if(child!=par) dfs(child, node, adj, lvl);
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> adj(n,vector<int>());
		for(int i=0; i<n-1; i++){
			int v; cin>>v; v--;
			adj[i+1].push_back(v);
			adj[v].push_back(i+1);
		}
		vector<int> lvl(n);
		dfs(0, -1, adj, lvl);
		// peek(lvl)
		vector<int> f(n, 0);
		for(int i = 0; i<n; i++){
			f[lvl[i]]++;
		}
		// peek(f)
		int ans = f[0];
		if(n>1) ans += f[1];
		int last = 1;
		for(int i = 2; i<n; i++){
			if(f[i-1]<=1) break;
			ans += ((f[i] * (f[i-1]-1))%998244353 * last)%998244353;
			ans %= 998244353;
			last *= (f[i-1]-1);
			last %= 998244353;
		}
		cout<<ans<<"\n";
	}
	return 0;
}