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

struct tri {
	int got;
	int maxi;
	int smaxi;
};
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0);
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		vector<int> b(n,0);
		for(int i = 0; i<n; i++){
			cin>>b[i];
		}
		for(int i = 0; i<n; i++){
			int maxi = max(a[i], b[i]);
			int mini = min(a[i], b[i]);
			a[i] = maxi;
			b[i] = mini;
		}
		vector<vector<tri>> dp(n, vector<tri>(n));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				dp[i][j] = {false, -1, -1};
			}
		}

		if(b[0]>a[0]||b[0]>a[1])
			dp[2][0] = {true, max(a[0], a[1]), b[0]};
		else if(b[1]>a[0]||b[1]>a[1])
			dp[2][0] = {true, max(a[0], a[1]), b[1]};
		else
			dp[2][0] = {true, max(a[0], a[1]), min(a[0], a[1])};

		for(int j = 1; j<n; j++){
			if(a[2] >= a[0] + a[1]){
			}
		}
		//index
		for(int i = 3; i<n; i++){
			//count
			for(int j = 0; j<n; j++){
				if(dp[i-1][j].got){
					dp[i][j] = dp[i-1][j];
					if(a[i]>=dp[i-1][j].maxi){
						dp[i][j].smaxi = dp[i-1][j].maxi;
						dp[i][j].maxi = a[i];
					} else if(a[i]>=dp[i-1][j].smaxi){
						dp[i][j].smaxi = a[i];
					}
				}  else if(dp[i-1][j-1].got){
					if(dp[i-1][j-1].maxi + dp[i-1][j-1].smaxi >= a[i]){
						dp[i][j] = dp[i-1][j-1];
						if(a[i]>=dp[i-1][j-1].maxi){
							dp[i][j].smaxi = dp[i-1][j-1].maxi;
							dp[i][j].maxi = a[i];
						} else if(a[i]>=dp[i-1][j-1].smaxi){
							dp[i][j].smaxi = a[i];
						}
					} else if(dp[i-1][j-1].maxi + dp[i-1][j-1].smaxi >= b[i]){
						dp[i][j] = dp[i-1][j-1];
						if(b[i]>=dp[i-1][j-1].maxi){
							dp[i][j].smaxi = dp[i-1][j-1].maxi;
							dp[i][j].maxi = b[i];
						} else if(a[i]>=dp[i-1][j-1].smaxi){
							dp[i][j].smaxi = b[i];
						}
					}
				}
			}
		}
	}
	return 0;
}