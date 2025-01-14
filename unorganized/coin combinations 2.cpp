#include<bits/stdc++.h>
// #define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int mod = 1000000007;
int ans(){
	fast_io;
	int n,x;
	cin>>n>>x;
	vector<int> coins(n);
	for(int i = 0; i<n; i++){
		cin>>coins[i];
	}
	vector<vector<int>> dp(n+1, vector<int>(x+1,0));
	for(int i = 0; i<n; i++){
		dp[i][0] = 1;
	}
	for(int i = 0; i<n; i++){
		for(int j = 1; j<=x; j++){
			if(j-coins[i]>=0) dp[i][j] = (dp[i][j] + dp[i][j-coins[i]])%mod;
			if(i-1>=0) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
		}
	}
	return dp[n-1][x];
}
int32_t main(){
	fast_io;
	cout<<ans();
	return 0;
}