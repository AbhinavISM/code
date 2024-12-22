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
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<vector<int>> dp(n, vector<int>(6,0));
	vector<string> perm = {"abc", "acb", "bac", "bca", "cab", "cba"};
	for(int j=0; j<6; j++){
		for(int i=0; i<n; i++){
			if(i-1>=0) dp[i][j] = dp[i-1][j] + ((s[i]!=perm[j][i%3])?1:0);
			else dp[i][j] = ((s[i]!=perm[j][i%3])?1:0);
		}		
	}
	for(int i=0; i<m; i++){
		int l,r;
		cin>>l>>r;
		l--;r--;
		int ans = INT_MAX;
		for(int j=0; j<6; j++){
			if(l-1>=0) ans = min(ans, dp[r][j] - dp[l-1][j]);
			else ans = min(ans, dp[r][j]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}