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
	int n, w;
	cin>>n>>w;
	vector<int> weights(n);
	vector<int> values(n);
	for(int i = 0; i<n; i++){
		cin>>weights[i]>>values[i];
	}
	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
	for(int i = n-1; i>=0; i--){
		for(int j = 0; j<=w; j++){
			if(j-weights[i]>=0) dp[i][j] = max(values[i] + dp[i+1][j - weights[i]], dp[i+1][j]);
			else dp[i][j] = dp[i+1][j];
		}
	}
	cout<<dp[0][w];
	return 0;
}