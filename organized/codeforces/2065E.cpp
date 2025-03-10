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
		int n,m,k;
		cin>>n>>m>>k;
		if(abs(n-m)>k || (n<k && m<k)) {
			cout<<-1<<"\n";
			continue;
		}
		vector<int> ans;
		bool zbig = (n>=m);
		int i = 0; int j = 0;
		while(i<n && j<m){
			if(zbig){
				int cur = 0;
				while(i<n && cur<k){
					ans.push_back(0);
					i++;
					cur++;
				}
				zbig = !zbig;
			} else {
				int cur = 0;
				while(j<m && cur<k){
					ans.push_back(1);
					j++;
					cur++;
				}
				zbig = !zbig;
			}
		}
		while(i<n){
			ans.push_back(0);
			i++;
		}
		while(j<m){
			ans.push_back(1);
			j++;
		}
		peek(ans)
	}
	return 0;
}