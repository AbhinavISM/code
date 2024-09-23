#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
ll rec(ll i, string &t, string &s, ll n, vector<map<string, ll>> &dp){
	if(t.length()>5) return 0;
	if(t.length()==5){
		if(t[0]==t[4]&&t[1]==t[3]) return 1;
		else return 0;
	}
	if(i==n){
		return 0;
	}
	if(dp[i].find(t)!=dp[i].end()) return dp[i][t];
	ll ans = rec(i+1,t,s,n,dp);
	t.push_back(s[i]);
	ans += rec(i+1,t,s,n,dp);
	t.pop_back();
	return dp[i][t] = ans;
}
ll getPalindromesCount(string &s){
	ll n = s.length();
	vector<map<string, ll>> dp(n, map<string,ll>());
	string t = "";
	return rec(0,t,s,n,dp);
}
int main(){
	fast_io;
	string s;
	cin>>s;
	cout<<getPalindromesCount(s);
}