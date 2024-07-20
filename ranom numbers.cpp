#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

ll rec(ll i, ll maxi, ll used, string &s, vector<vector<vector<ll>>> &dp, map<char,ll> &val){
	if(i==s.length()) return 0;
	if(dp[i][maxi][used]!=INT_MIN) return dp[i][maxi][used];
	ll ans = INT_MIN;
	for(ll j = 0; j<5; j++){
		if((s[i]-'A'!=j)&&used==0)
		ans = max(ans,rec(i+1,max(maxi, j),1,s,dp,val) + ((maxi<=j)?1:-1)*val['A'+j]);
		else if(s[i]-'A'==j)
		ans = max(ans,rec(i+1,max(maxi, j),used,s,dp,val) + ((maxi<=j)?1:-1)*val['A'+j]);
	}
	return dp[i][maxi][used] = ans;
}
ll rn(string &s){
	ll n = s.length();
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(5,vector<ll>(2,INT_MIN)));
	map<char,ll> val;
	val['A'] = 1, val['B'] = 10, val['C'] = 100, val['D'] = 1000, val['E'] = 10000;
	reverse(s.begin(), s.end());
	return rec(0,0,0,s,dp,val);
}
int main(){
	fast_io;
	ll t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	cout<<rn(s)<<"\n";
}
	return 0;
}