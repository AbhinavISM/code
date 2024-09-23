#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n,w;
	cin>>n>>w;
	vector<int> weights(n);
	vector<int> values(n);
	for(int i = 0; i<n; i++){
		cin>>weights[i]>>values[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(w+1,0));
	for(int i = n-1; i>=0; i--){
		for(int j = 0; j<=w; j++){
			if(j-weights[i]>=0) dp[i][j] = max(values[i] + dp[i+1][j-weights[i]], dp[i+1][j]);
			else dp[i][j] = max(0ll, dp[i+1][j]);
		}
	}
	cout<<dp[0][w];
	return 0;
}