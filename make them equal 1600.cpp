#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	vector<int> cost(1001, INT_MAX);
	cost[1] = 0;
	for(int i = 1; i<=1000; i++){
		for(int j = 1; j<=i; j++){
			if(i+i/j<=1000)cost[i + i/j] = min(cost[i]+1, cost[i + i/j]);
		}
	}
	while(t--){

	int n,k;
	cin>>n>>k;
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	vector<int> c(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		c[i] = item;
	}
	if(k>=20*n){
		int ans = 0;
		for(int i = 0; i<n; i++){
			ans += c[i];
		}
		cout<<ans<<"\n";
		continue;
	}
	vector<vector<int>> dp(n+1, vector<int>(k+1,0));
	for(int i = n-1; i>=0; i--){
		for(int j = 0; j<=k; j++){
			if(j-cost[b[i]]>=0) dp[i][j] = max(dp[i+1][j-cost[b[i]]] + c[i], dp[i+1][j]);
			else dp[i][j] = max(0ll, dp[i+1][j]);
		}
	}
	cout<<dp[0][k]<<"\n";
}
	return 0;
}