#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int x;
	cin>>x;
	int hi = 10000;
	int lo = 1;
	bool voila = false;
	while(hi>=lo){
		int ans = hi*hi*hi + lo*lo*lo;
		if(ans==x){
			voila = true;
			break;
		} else if(ans>x){
			hi = hi-1;
		} else {
			lo = lo + 1;
		}
	}
	if(voila){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}