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
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector<int> a(n);
		vector<int> p(n);
		map<int,int> f;
		p[0] = s[0]-'0';
		a[0] = p[0];
		a[0] -= 1;
		f[a[0]]++;
		for(int i = 1; i<n; i++){
			p[i] = p[i-1] + (int)(s[i] - '0');
			a[i] = p[i];
			a[i] -= (i+1);
			f[a[i]]++;
		}
		int ans = 0;
		ans += f[0];
		f[a[0]]--;
		for(int i = 1; i<n; i++){
			ans += f[p[i-1]-i];
			f[a[i]]--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}