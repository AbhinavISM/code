#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(vector<int> &dp, int i, vector<int> &h){
	if(i==0){
		return dp[i]=0;
	}
	if(i==1){
		return dp[i]=abs(h[1]-h[0]);
	}
	if(dp[i]!=-1){return dp[i];}
	int cost1 = abs(h[i] - h[i-1]) + ((dp[i-1]!=-1)?dp[i-1]:solve(dp,i-1,h));
	int cost2 = abs(h[i] - h[i-2]) + ((dp[i-2]!=-1)?dp[i-2]:solve(dp,i-2,h));
	dp[i] = min(cost2, cost1);
	return dp[i];
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> h(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		h[i] = item;
	}
	vector<int> dp(n,-1);
	cout<<solve(dp,n-1,h);
	// dp[1] = abs(h[1]-h[0]);
	// for(int i = 2; i<n; i++){
	// 	dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
	// }
	return 0;
}