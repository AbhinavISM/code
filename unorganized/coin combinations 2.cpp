#include<bits/stdc++.h>
// #define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(int i, int n, int x, vector<vector<int>>&dp, vector<int>&array){
	if(i>=n+1||x<0){
		return 0;
	}
	if(dp[i][x]!=-1){
		return dp[i][x];
	}
	if(x==0){
		return 1;
	}
	int a,b;
	if(x-array[i]>=0){
		if(dp[i][x-array[i]]==-1){
			a = solve(i, n, x-array[i], dp, array);
		} else {
			a = dp[i][x-array[i]];
		}
	} else {
		a = 0;
	}
	if(i<n){
		if(dp[i+1][x]==-1){
			b = solve(i+1, n, x, dp, array);
		} else {
			b = dp[i+1][x];
		}
	} else {
		b = 0;
	}
	// cout<<a<<" "<<b<<"\n";
	return dp[i][x] = (a + b);
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int x;
	cin>>x;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<vector<int>> dp(n+1, vector<int>(x+1,0));
	for(int i = 0; i<n; i++){
		dp[i][0] = 1;
	}
	for(int j = 1; j<=x; j++){
	for(int i = n-1; i>=0; i--){
			int a,b;
			a=0;
			b=0;
			a = dp[i+1][j];
			if(j-array[i]>=0){
				b = dp[i][j-array[i]];
			}
			dp[i][j] = (a+b)%1000000007;
		}
	}
	cout<<dp[0][x];
	// cout<<solve(1,n,x,dp,array);
	return 0;
}