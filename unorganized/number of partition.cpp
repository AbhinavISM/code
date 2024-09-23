#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int main(){
	fast_io;
	ll t;
	cin>>t;
	while(t--){
	ll n;
	cin>>n;
	vector<ll> a(n+1,0);
	vector<ll> pre(n+1,0);
	for(ll i = 1; i<=n; i++){
		cin>>a[i];
		pre[i] = pre[i-1] + a[i];
	}
	map<ll,ll> f;
	map<ll,ll> b;
	ll ans = 0;
	for(ll i = 1; i<=n; i++){
		ll lsum = pre[i] - pre[0];
		ll rsum = pre[n] - pre[i];
		if(lsum==rsum) ans++;
		b[lsum-rsum]++;
	}
	for(ll i = 1; i<=n; i++){
		ll lsum = pre[i] - pre[0];
		ll rsum = pre[n] - pre[i];
		ll d = lsum-rsum;
		f[d]++;
		b[d]--;
		ans = max(ans, b[a[i]] + f[-1*a[i]]);
	}
	cout<<ans<<"\n";
}
	return 0;
}