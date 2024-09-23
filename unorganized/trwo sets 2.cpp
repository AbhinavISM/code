#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
// if(i<=0){
// 		return 0;
// 	}
// 	if(reqiredsum==0){
// 		return 1;
// 	} else if(reqiredsum<0){
// 		return 0;
// 	}
// 	int ans = 0;
// 	int diff = 0;
// 	for(int j = i; j>=1; j--){
// 		diff+=j;
// 		ans += rec(j-1,n,reqiredsum-diff);
// 	}
// 	return ans;
int rec(int i, vector<vector<int>> &dp, int reqiredsum){

	if(i<=0){
		return 0;
	}
	if(reqiredsum==0){
		return 1;
	} else if(reqiredsum<0){
		return 0;
	}
		if(dp[i][reqiredsum]!=-1){
		return dp[i][reqiredsum];
	}
	return dp[i][reqiredsum]=(rec(i-1,dp,reqiredsum-i) + rec(i-1,dp,reqiredsum))%1000000007;
}
void solve(int n){
	int reqiredsum = (((n+1)*n)/4);
	vector<vector<int>> dp(n+1,vector<int>((((n+1)*n)/4)+1,0));
	dp[0][0]=1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=(((n+1)*n)/4); j++){
			dp[i][j] = ((j<i)?0:dp[i-1][j-i]) + dp[i-1][j];
			dp[i][j]%=1000000007;
		}
	}
	cout<<dp[n][reqiredsum];
}
int32_t main(){
	int n;
	cin>>n;
	if((((n+1)*n)/2)%2){
		cout<<0;
	} else {
		solve(n);
	}
}