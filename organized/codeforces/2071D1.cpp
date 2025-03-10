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
int solve(int l, int n, vector<int> &a, vector<int> &prexor){
	if(l<=2*n){
		return a[l];
	}
	int mid = l/2;
	if(mid%2){
		return prexor[n];
	} else {
		return prexor[n]^solve(mid, n, a, prexor);
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n, l, r;
		cin>>n>>l>>r;
		vector<int> a(n+1,0);
		for(int i = 1; i<=n; i++){
			cin>>a[i];
		}
		vector<int> prexor(n+1, 0);
		prexor[1] = a[1];
		for(int i=2; i<=n; i++){
			prexor[i] = prexor[i-1]^a[i];
		}
		if(n%2==0){
			a.push_back(prexor[n/2]);
			prexor.push_back(prexor[n]^a[n+1]);
			n++;
		}
		for(int i = 1; i<=n; i++){
			a.push_back(prexor[(n+i)/2]);
		}
		cout<<solve(l, n, a, prexor)<<"\n";
	}
	return 0;
}