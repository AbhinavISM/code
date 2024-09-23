#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int target = (n*(n+1))/2;
	if(target%2){
		cout<<0;
		return 0;
	}
	target/=2;
	vector<vector<int>> dp(n+2, vector<int>(target + 1,0));
	dp[0][0] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=target; j++){
			if(j>=0){
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= 1000000007;
			}
			if(j-i>=0){
				dp[i][j] += dp[i-1][j - i];
				dp[i][j] %= 1000000007;
			}
		}
	}
	cout<<dp[n][target];
	return 0;
}