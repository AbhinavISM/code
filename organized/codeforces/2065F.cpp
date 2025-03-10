#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> nodeval(n);
		for(int i = 0; i<n; i++){
			int val; cin>>val; val--;
			nodeval[i] = val;
		}
		vector<vector<int>> adj(n, vector<int>());
		for(int i = 0; i<n-1; i++){
			int u,v;
			cin>>u>>v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> ans(n, 0);
		for(int i = 0; i<n; i++){
			map<int, int> f;
			f[nodeval[i]]++;
			for(int child : adj[i]){
				f[nodeval[child]]++;
				if(f[nodeval[child]]>1) ans[nodeval[child]] = 1; 
			}
		}
		peek(ans)
	}
	return 0;
}