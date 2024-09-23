#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int rec(int x, int y, bool tight, string &num, vector<vector<vector<int>>> &dp){
	if(y<0) return 0;
	if(x==0) {
		return 1;
	}
	if(dp[x][y][tight]!=-1) return dp[x][y][tight];
	int ans = 0;
	int ub = tight?(num[num.length()-x]-'0'):9;
	for(int dig = 0; dig<=ub; dig++){
		if(dig==0) ans += rec(x-1, y, (tight&&(dig==ub)), num, dp);
		else ans += rec(x-1, y-1, (tight&&(dig==ub)), num, dp);
	}
	return dp[x][y][tight] = ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int l,r;
	cin>>l>>r;
	string ls = to_string(l-1); string rs = to_string(r);
	int n = ls.length(); int m = rs.length();
	vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(4,vector<int>(2,-1)));
	int a = rec(m,3,1,rs,dp);
	dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(4,vector<int>(2,-1)));
	int b = rec(n,3,1,ls,dp);
	cout<<a-b<<"\n";
}
	return 0;
}