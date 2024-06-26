#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int binexp(int x, int y){
	int ans = 1;
	while(y>0){
		if(y%2) ans *= x;
		x = x*x;
		y /= 2; 
	}
	return ans;
}
int cnt(int n, bool tight, string &num){
	if(n==0) return 0;
	if(!tight) return binexp(10,n)-1;

	int ans = 0;
	int f = 1;
	for(int i = 0; i<n; i++){
		ans += f*(num[num.length()-i-1]-'0');
		f *= 10;
	}
	return ans;
}
int rec(int n, bool tight, string &num, vector<vector<int>> &dp){
	if(n<=0) return 0;
	if(dp[n][tight]!=-1) return dp[n][tight];
	int ub = tight?(num[num.length()-n]-'0'):9;
	int ans = 0;
	for(int dig = 0; dig<=ub; dig++){
		ans += dig*(cnt(n-1, tight&&(dig==ub), num)+1);
		ans += rec(n-1, tight&&(dig==ub), num, dp);
	}
	return dp[n][tight] = ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	n--;
	string ns = to_string(n); string ms = to_string(m);
	vector<vector<int>> dp(ms.size()+1,vector<int>(2,-1));
	int a = rec(ms.length(),1,ms,dp);
	dp = vector<vector<int>> (ns.size()+1,vector<int>(2,-1));
	int b = rec(ns.length(),1,ns,dp);
	cout<<a-b<<"\n";
}
	return 0;
}