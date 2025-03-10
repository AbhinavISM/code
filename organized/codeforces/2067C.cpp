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
bool find7(int n){
	while(n>0){
		if(n%10==7) return true;
		n/=10;
	}
	return false;
}
int solve(int n){
	if(find7(n)) return 0; 
	vector<int> a = {9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999};
	int ans = 7;
	for(int i=0; i<a.size(); i++){
		int tn = n;
		for(int j = 1; j<=7; j++){
			tn += a[i];
			if(find7(tn)) ans = min(ans, j);
		}
	}
	return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<solve(n)<<"\n";
	}
	return 0;
}