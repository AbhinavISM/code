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

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,d,l;
		cin>>n>>d>>l;
		if(l<2||n<d-1+l) {
			cout<<-1<<"\n";
			continue;
		}
		int depth = d/2;
		if(depth==0){
			if(l==0&&n==2){
				cout<<1<<" "<<2<<"\n";
				continue;
			} else {
				cout<<-1<<"\n";
				continue;
			}
		}
		int internalcnt = n - (d-1) - l;
		if((internalcnt + depth - 1)/depth <= l){
			vector<vector<int>> edges;
			for(int i = 1; i<d; i++){
				edges.push_back({i, i+1});
			}
			int node = d+1;
			for(int i = 0; i<(internalcnt + depth - 1)/depth; i++){
				int last = (n+1)/2;
				for(int j = 0; j<depth; j++){
					edges.push_back({last, node});
					last = node;
					node++;
					if(node==n+1) break;
				}
			}
			while(node<=n){
				edges.push_back({(n+1)/2, node});
				node++;
			}
			dpeek(edges)
		} else {
			cout<<-1<<"\n";
			continue;
		}
	}
	return 0;
}