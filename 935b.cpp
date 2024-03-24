#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int a,b,m;
	cin>>a>>b>>m;
	// int lcm = __gcd(a,b);
	// lcm = (a/gcd)*b;
	int lcm = 0;
	int ans = ((lcm+m)/a - (lcm)/a) + 1;
	ans += ((lcm+m)/b - (lcm)/b) + 1;
	cout<<ans<<"\n";
}
	return 0;
}