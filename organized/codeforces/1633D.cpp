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
	vector<int> cost(1001, INT_MAX);
	cost[1] = 0;
	for(int i = 1; i<=1000; i++){
		for(int j = 1; j<=i; j++){
			if(i+i/j<=1000)cost[i + i/j] = min(cost[i]+1, cost[i + i/j]);
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> b(n,0);
		for(int i = 0; i<n; i++){
			cin>>b[i];
		}
		vector<int> c(n,0);
		for(int i = 0; i<n; i++){
			cin>>c[i];	
		}
		vector<int> o(n,0);
		int maxkneed = 0;
		for(int i = 0; i<n; i++){
			o[i] = cost[b[i]];
			maxkneed += o[i];
		}
		if(k>maxkneed) k = maxkneed;
		vector<vector<int>> dp(n, vector<int>(k+1,0));
		for(int j = 0; j<=k; j++){
			for(int i=0; i<n; i++){
				if(i>0){
					if(j-o[i]>=0)
						dp[i][j] = max(dp[i-1][j], dp[i-1][j-o[i]] + c[i]);
					else
						dp[i][j] = dp[i-1][j];
				} else {
					if(j-o[i]>=0)
						dp[i][j] = c[i];
				}
			}
		}
		cout<<dp[n-1][k]<<"\n";
	}
	return 0;
}