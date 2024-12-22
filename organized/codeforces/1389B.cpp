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
		int n,K,z;
		cin>>n>>K>>z;
		vector<int> a(n,0);
		int score = 0;
		for(int i = 0; i<n; i++){
			cin>>a[i];
			if(i<=K) score += a[i];
		}
		vector<int> pre(n,0);
		pre[0] = a[0];
		for(int i = 1; i<n; i++){
			pre[i] = pre[i-1] + a[i];
		}
		for(int i = 0; i<n-1&&i<=K; i++){
			int k = K;
			int ans = a[0];
			ans += (pre[i]-pre[0]);
			k-=i;
			if(k>=2*z){
				ans += z*(a[i+1]+a[i]);
				k-=2*z;
				if(i+k<n) ans += (pre[i+k]-pre[i]);
				else ans += (pre[n]-pre[i]);
			} else{
				if(k%2){
					ans += (k/2*(a[i+1]+a[i]) + a[i+1]);
				} else{
					ans += k/2*(a[i+1]+a[i]);
				}
			}
			score = max(ans, score);
		}
		cout<<score<<"\n";
	}
	return 0;
}