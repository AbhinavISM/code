#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	int mod = 1000000007;
	vector<int> tests;
	while(t--){
		int n;
		cin>>n;
		tests.push_back(n);
	}
	vector<vector<int>> dp(1000002,vector<int>(2,0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i = 2; i<=1000000; i++){
		dp[i][0] = (4LL*dp[i-1][0] + dp[i-1][1])%mod;
		dp[i][1] = (dp[i-1][0] + 2LL*dp[i-1][1])%mod;
	}
	for(int tst : tests){
		cout<<(dp[tst][1] + dp[tst][0])%mod<<"\n";
	}
	return 0;
}