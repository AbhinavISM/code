#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int rec(string &num, int dont, int i, bool tight, bool leadingZero, vector<vector<vector<vector<int>>>> &dp){
	if(i==0) return 1;
	if(dp[dont][i][tight][leadingZero]!=-1) return dp[dont][i][tight][leadingZero];
	int ub = tight?(num[num.size()-i]-'0'):9;
	int ans = 0;
	for(int dig = 0; dig<=ub; dig++){
		if(dig!=dont||leadingZero) ans += rec(num,dig,i-1,tight&&(dig==ub),leadingZero&&(dig==0),dp);
	}
	return dp[dont][i][tight][leadingZero] = ans;
}
int32_t main(){
	fast_io;
	int a,b;
	cin>>a>>b;
	a--;
	string as = to_string(a); int n = as.length();
	string bs = to_string(b); int m = bs.length();
	vector<vector<vector<vector<int>>>> dp(10,vector<vector<vector<int>>>(m+1,vector<vector<int>>(2,vector<int>(2,-1))));
	int y = rec(bs,0,m,1,1,dp);
	dp = vector<vector<vector<vector<int>>>> (10,vector<vector<vector<int>>>(n+1,vector<vector<int>>(2,vector<int>(2,-1))));
	int x = rec(as,0,n,1,1,dp);
	cout<<y-x;
}