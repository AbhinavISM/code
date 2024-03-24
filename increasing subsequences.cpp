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
	int x;
	cin>>x;
	int hi = 63;
	int lo = 0;
	int ans = 0;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(x>=(1ll<<mid)){
			lo = mid + 1;
			ans = max(ans,mid);
		} else {
			hi = mid - 1;
		}
	}
	x-=(1ll<<ans);
	vector<int> print;
	for(int i=1; i<=ans; i++){
		print.push_back(i);
	}
	while(x>0){
		int hi = 63;
		int lo = 0;
		int ans = 0;
		while(hi>=lo){
			int mid = lo + (hi-lo)/2;
			if(x>=(1ll<<mid)){
				lo = mid + 1;
				ans = max(ans,mid);
			} else {
				hi = mid - 1;
			}
		}
		print.push_back(ans+1);
		x-=(1ll<<ans);
	}
	cout<<print.size()<<"\n";
	peek(print)
}
	return 0;
}