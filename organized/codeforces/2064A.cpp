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
int solve(int n, vector<int> serviceLimits){
	int scnt = serviceLimits.size();
	vector<vector<int>> dp(n+1, vector<int>(scnt, 0));
	for(int j = 0; j<scnt; j++){
		dp[1][j] = 1;
	}
	for(int i = 2; i<=n; i++){
		for(int j = 0; j<scnt; j++){
			for(int k = 0; k<scnt; k++){
				if(j!=k) dp[i][j] += dp[i-1][k]*min(i-1, serviceLimits[k]); 				
			}
			dp[i][j] += dp[i-1][j] * min(i-1, serviceLimits[j]-1);
		}
	}
	int ans = 0;
	for(int j = 0; j<scnt; j++) {
		ans += (dp[n][j] * min(n, serviceLimits[j]));
	}
	return ans;
}
int32_t main(){
	fast_io;
	cout<<solve(4, {1, 1, 1, 1, 1});
	return 0;
}