#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	string b;
	cin>>b;
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	int ans = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = max(dp[i-1][j-1]+2, dp[i][j]);
			} else {
				dp[i][j] = max({dp[i-1][j]-1, dp[i][j-1]-1,dp[i][j]});
				// if(dp[i][j]<0){dp[i][j]=0;}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}