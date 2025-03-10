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
		vector<int> c(n,0);
		for(int i = 0; i<n; i++){
			cin>>c[i];
		}
		sort(c.begin(), c.end());
		vector<int> cf = c;
		for(int i = 1; i<n; i++){
			cf[i] += cf[i-1];
		}
		// peek(c)
		vector<int> ans;
		for(int m = 1; m<=n; m++){
			int a = m%(k+1);
			int b = m/(k+1);
			int tans = 0;
			// cout<<a<<" "<<b<<"\n";
			if(a>=1) tans += cf[a-1];			
			if(a>=1) tans += cf[b*(k+1) + a-1] - cf[a-1];
			else tans += cf[b*(k+1) - 1];
			for(int i = 0; i<b; i++){
				tans -= c[a + i*(k+1)];
			}
			ans.push_back(tans);
		}
		peek(ans)
	}
	return 0;
}