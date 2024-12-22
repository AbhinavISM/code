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
		int n,k;
		cin>>n>>k;
		vector<int> a(n,0);
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		bool good = false;
		int ans;
		for(int i = 0; i<n; i++){
			bool gud = true;
			for(int j = 0; j<n; j++){
				if(i!=j){
					if(abs(a[i] - a[j]) % k == 0){
						gud = false;
						break;
					}	
				}
			}
			if(gud){
				good = true;
				ans = i+1;
				break;
			}
		}
		if(good){
			cout<<"YES\n";
			cout<<ans<<"\n";
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}