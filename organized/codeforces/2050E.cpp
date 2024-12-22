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
		string a;
		cin>>a;
		string b;
		cin>>b;
		string c;
		cin>>c;
		int n = a.length();
		int m = b.length();
		vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
		dp[0][0] = 0;
		for(int j = 1; j<=m; j++){
			dp[0][j] = dp[0][j-1] + (b[j-1]==c[j-1]?0:1);
		}
		for(int i = 1; i<=n; i++){
			dp[i][0] = dp[i-1][0] + (a[i-1]==c[i-1]?0:1);
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(i>=2){
					dp[i][j] = min(dp[i][j], dp[i-2][j] + (a[i-1 -1]==c[i+j -2]?0:1) + (a[i -1]==c[i+j+1 -2]?0:1));	
				}
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i -1]==c[i+j -2]?0:1) + (b[j -1]==c[i+j+1 -2]?0:1));
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (b[j -1]==c[i+j -2]?0:1) + (a[i -1]==c[i+j+1 -2]?0:1));
				if(j>=2){
					dp[i][j] = min(dp[i][j], dp[i][j-2] + (b[j-1 -1]==c[i+j -2]?0:1) + (b[j -1]==c[i+j+1 -2]?0:1));
				}
			}
		}
		cout<<dp[n][m]<<"\n";
	}
	return 0;
}