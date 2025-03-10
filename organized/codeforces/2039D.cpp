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

//correct
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(m+1,INT64_MAX);
		for(int i = 1; i<=m; i++){
			cin>>a[i];
		}
		sort(a.begin(), a.end(), greater<int>());
		vector<int> ans = vector<int>(n+1, 1);
		bool good = true;
		for(int i = 1; i<=n; i++){
			for(int j = 2*i; j<=n; j+=i){
				if(a[ans[gcd(i, j)]]==gcd(a[ans[i]],a[ans[j]])){
					if(ans[i]!=m) ans[j] = ans[i] + 1;
					else good = false;
				}
			}
		}
		if(good) {
			for(int i = 1; i<=n; i++) cout<<a[ans[i]]<<" ";
				cout<<"\n";
		} else {
			cout<<-1<<"\n";
		}
	}
	return 0;
}