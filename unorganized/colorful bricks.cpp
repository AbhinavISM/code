#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> dp(n+1, vector<int>(k+1,0));
	dp[1][0] = m;
	for(int i = 2; i<=n; i++){
		for(int j = 0; j<=k; j++){
			if(j!=0) dp[i][j] = (dp[i-1][j]*1 + ((dp[i-1][j-1]*(m-1))%998244353))%998244353;
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][k];
	return 0;
}