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
		int m, a, b, c;
		cin>>m>>a>>b>>c;
		int m1 = m;
		int m2 = m;
		int ans = 0;
		if(a>m){
			ans += m1;
			m1 = 0;
		} else {
			ans += a;
			m1 -= a;
		}
		if(b>m){
			ans += m2;
			m2 = 0;
		} else {
			ans += b;
			m2 -= b;
		}
		if(c>m1+m2){
			ans += (m1+m2);
		} else {
			ans += c;
		}
		cout<<ans<<"\n";
	}
	return 0;
}