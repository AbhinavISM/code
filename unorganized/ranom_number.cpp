#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

map<char, ll> mp;


ll rec(ll ind, ll mx, ll chng, string &s, vector<vector<vector<ll>>> &dp){
	if(ind == -1) return 0;
	if(dp[ind][mx][chng] != -1) return dp[ind][mx][chng];
	ll sign = 1;
	if(s[ind] - 'A' < mx) sign = -1;
	ll ans = (sign * mp[s[ind]]) + rec(ind-1, max(mx, (ll)(s[ind] - 'A')), chng, s, dp);
	if(!chng){
		for(ll i=0; i<5; i++){
			ll sign = 1;
			if(i < mx){
				sign = -1;
			}
			ll tmp = (sign * mp[i + 'A']) + rec(ind - 1, max(mx, i), 1, s, dp);
			ans = max(ans, tmp);
		}
	}
	return dp[ind][mx][chng] = ans;
}

int main(){
	fast_io;
	ll t;
	cin>>t;
	mp['A'] = 1, mp['B'] = 10, mp['C'] = 100, mp['D'] = 1000, mp['E'] = 10000;
	while(t--){
		string s;
		cin>>s;
		ll n = s.size();
		vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (5, vector<ll> (2, -1)));
		ll ans = rec(n-1, 0, 0, s, dp);
		cout<<ans<<'\n';
	}
	return 0;
}