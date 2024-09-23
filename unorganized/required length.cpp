#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
#define inf INT64_MAX

map<int,int> dp;
int solve(int &n, int x){
	// cout<<x<<"\n";
	if(dp[x]!=0){
		return dp[x];
	}
	int tmp = x;
	int digitcnt = 0;
	while(tmp>0){
		digitcnt++;
		tmp/=10;
	}
	if(digitcnt==n){
		return dp[x]=0;
	}
	if(digitcnt>n){
		return dp[x]=inf;
	}
	tmp = x;
	int ans = inf;
	while(tmp>0){
		int y = tmp%10;
		tmp/=10;
		if(y!=1&&y!=0){
			int res = solve(n, x * y);
			if (res != inf) {
			    ans = min(ans, 1 + res);
			}
		}
	}
	return dp[x]=ans;
}
int32_t main(){
	fast_io;
	int n,x;
	cin>>n>>x;
	int ans = solve(n,x);
	cout<<((ans!=inf)?ans:-1);
	return 0;
}