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
vector<int> solve(int n, int k){	
	if(n==1){
		return {k};
	}
	if(n==2){
		return {k,k};
	}
	vector<int> ans;
	for(int i = 20; i>=1; i--){
		if(n == (1<<i)){
			for(int j = 0; j<n; j++){
				ans.push_back(k);
			}
			return ans;
		}
		if(n > (1<<i)){
			vector<int> a = solve(n%(1<<i), k);
			ans = a;
			for(int j = 0; j<n-2*a.size(); j++){
				ans.push_back(0);
			}
			ans.insert(ans.end(), a.begin(), a.end());
			return ans;
		}
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		peek(solve(n, k));
	}
	return 0;
}