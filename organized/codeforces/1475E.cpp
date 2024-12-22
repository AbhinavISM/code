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
int mod = 1000000007;
vector<int> fact(1001, 1);
void computeFact(){
	for(int i = 1; i<1001; i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
}
int binexp(int x, int y){
	if(y==0) return 1;
	int res = binexp(x,y/2);
	if(y%2) return (x*((res*res)%mod))%mod;
	else return (res*res)%mod;
}
int inv(int x){
	return binexp(x, mod-2)%mod;
}
int ncr(int n, int r){
	if(n<r) return -1;
	return (fact[n]*inv((fact[r]*fact[n-r])%mod))%mod;
}
int32_t main(){
	fast_io;
	computeFact();
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n,0);
		vector<int> f(n+1,0);
		for(int i = 0; i<n; i++){
			cin>>a[i];
			f[a[i]]++;
		}
		int need = k;
		int ans = 1;
		for(int i=n; i>=1; i--){
			if(need>f[i]){
				need -= f[i];
			} else {
				ans = ncr(f[i], need);
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}