#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int solve(int n, int &m, int &c0, int&d0,
	vector<int>a, vector<int>&b, vector<int>&c,
	vector<int>&d, vector<map<vector<int>,int>>&dp){
	if(n<=0){
		return 0;	
	}
	if(dp[n][a]!=0){
		return dp[n][a];
	}
	int ans = 0;
	if(n-c0>=0){
		ans = solve(n-c0,m,c0,d0,a,b,c,d,dp) + d0;
	}
	for(int i = 1; i<=m; i++){
		if(a[i]-b[i]>=0&&n-c[i]>=0){
			int tmp = a[i];
			a[i] -= b[i];
			ans = max(ans, solve(n-c[i],m,c0,d0,a,b,c,d,dp) + d[i]);
			a[i] = tmp;	
		}
	}
	dp[n][a] = ans;
	return ans;
}
int32_t main(){
	fast_io;
	int n,m,c0,d0;
	cin>>n>>m>>c0>>d0;
	vector<int> a(m+1);
	vector<int> b(m+1);
	vector<int> c(m+1);
	vector<int> d(m+1);
	for(int i = 1; i<=m; i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	vector<map<vector<int>,int>> dp(n+1);
	for(int i = 1; i<=n; i++){
		
		int ans = 0;
		if(i-c0>=0){
			ans = dp[i-c0][a] + d0;
		}
		for(int j = 1; j<=m; j++){
			if(a[j]-b[i]>=0&&n-c[i]>=0){
				int tmp = a[i];
				a[i] -= b[i];
				ans = dp[i-c[i]][a] + d[i];
				a[i] = tmp;
			}
		}
		dp[n][a] = ans;
	}
	cout<<solve(n,m,c0,d0,a,b,c,d,dp);
}