#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n,h,l,r;
	cin>>n>>h>>l>>r;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<vector<int>> dp(n, vector<int>(h,-1));
	if(a[0]>=l&&a[0]<=r){
		dp[0][a[0]] = 1;
	} else {
		dp[0][a[0]] = 0;
	}
	if((a[0]-1)>=l&&(a[0]-1)<=r){
		dp[0][a[0]-1] = 1;
	} else {
		dp[0][a[0]-1] = 0;
	}
	for(int i = 1; i<n; i++){
		for(int j = 0; j<h; j++){
			if(dp[i-1][j]!=-1){
				// if(j>=l&&j<=r){
				// 	dp[i][j] = dp[i-1][j] + 1;					
				// } else {
				// 	dp[i][j] = dp[i-1][j];
				// }
				if(((j+a[i])%h)>=l&&((j+a[i])%h)<=r){
					dp[i][(j+a[i])%h] = max(dp[i][(j+a[i])%h],dp[i-1][j] + 1);
				} else {
					dp[i][(j+a[i])%h] = max(dp[i][(j+a[i])%h],dp[i-1][j]);
				}
				if(((j+a[i]-1)%h)>=l&&((j+a[i]-1)%h)<=r){
					dp[i][(j+a[i]-1)%h] = max(dp[i][(j+a[i]-1)%h],dp[i-1][j] + 1);
				} else {
					dp[i][(j+a[i]-1)%h] = max(dp[i][(j+a[i]-1)%h],dp[i-1][j]);
				}
			}
		}
	}
	// for(int i = 0; i<n; i++){
	// 	for(int j = 0; j<h; j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	int ans = 0;
	for(int i = 0; i<h; i++){
		ans = max(ans,dp[n-1][i]);
	}
	cout<<ans;
	return 0;
}