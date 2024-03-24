#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int a,b;
	cin>>a>>b;
	int ans =((a*b)/__gcd(a,b));
	if(ans==b){
		ans = ans*(b/a);
	}
	cout<<ans<<"\n";
}
	return 0;
}