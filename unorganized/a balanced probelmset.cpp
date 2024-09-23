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
	int x,n;
	cin>>x>>n;
	int ans = 1;
	for(int d = 1; d*d<=x; d++){
		if(x%d==0){
			int xbyd = x/d;
			if(d>=n){
				ans = max(ans,xbyd);
			} else if(xbyd>=n){
				ans = max(ans,d);
			}
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}