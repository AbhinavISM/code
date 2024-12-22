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

void dfs(int node, int n, vector<vector<int>> &adj, set<int> &s, vector<int> &ans, int nodeval, int par){
	for(int child : adj[node]){
		if(child==par) continue;
		if(nodeval != 1 && s.find(nodeval-1)!=s.end()){
			ans[child] = nodeval-1;
			s.erase(nodeval-1);
			dfs(child, n, adj, s, ans, ans[child], node);
		} else if(nodeval != 2*n && s.find(nodeval+1)!=s.end()){
			ans[child] = nodeval+1;
			s.erase(nodeval+1);
			dfs(child, n, adj, s, ans, ans[child], node);
		} else {
			int lo = 1;
			int hi = 2*n;
			int p = INT_MAX;
			while(hi>=lo){
				int mid = lo + (hi-lo)/2;
				int p1 = nodeval-2*mid-2;
				if(p1<0){
					hi = mid - 1;
				} else if(s.find(p1)!=s.end()){
					p = min(p, p1);
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if(p!=INT_MAX){
				ans[child] = p;
				s.erase(p);
				dfs(child, n, adj, s, ans, ans[child], node);
				continue;
			}
			lo = 1;
			hi = 2*n;
			p = INT_MAX; //check it
			while(hi>=lo){
				int mid = lo + (hi-lo)/2;
				int p1 = nodeval+2*mid+2;
				if(p1>2*n){
					hi = mid - 1;
				} else if(s.find(p1)!=s.end()){
					p = min(p, p1);
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			if(p!=INT_MAX){
				ans[child] = p;
				s.erase(p);
				dfs(child, n, adj, s, ans, ans[child], node);
				continue;
			}
		}
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int> s;
		for(int i = 1; i<=2*n; i++){
			s.insert(i);
		}
		vector<vector<int>> adj(n, vector<int>());
		for(int i = 0; i<n-1; i++){
			int u,v;
			cin>>u>>v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> ans(n,0);
		ans[0] = 1;
		s.erase(1);
		dfs(0, n, adj, s, ans, 1, -1);
		peek(ans)
	}
	return 0;
}