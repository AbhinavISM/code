#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n,w;
	cin>>n>>w;
	vector<int> weights(n+1);
	vector<int> values(n+1);
	for(int i = 1; i<=n; i++){
		cin>>weights[i]>>values[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(100001,INT_MAX));
	for(int i = 1; i<=100000; i++){
		dp[0][i] = INT_MAX;
	}
	for(int i = 1; i<=n; i++){
		for(int val = 1; val<=100000; val++){
			if(val-values[i]>0)dp[i][val] = min(dp[i-1][val-values[i]] + weights[i], dp[i-1][val]);
			else dp[i][val] = min(weights[i], dp[i-1][val]);
			
			// if(i==1&&val==31){cout<<dp[i][val]<<" ";}
		}
	}
	int ans = 0;
	for(int i = 1; i<=100000; i++){
		if(dp[n][i]<=w) ans = i;
	}
	cout<<ans;
	return 0;
}