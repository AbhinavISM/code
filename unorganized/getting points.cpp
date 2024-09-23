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
	int n,p,l,t;
	cin>>n>>p>>l>>t;
	int tcnt = (n-1)/7;
	tcnt++;
	int ans = INT_MAX;
	int lo = 0;
	int hi = n;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int pts = mid*l;
		if(tcnt<=mid*2){
			pts += tcnt*t;
		} else {
			pts += mid*2*t;
		}
		if(pts>=p){
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout<<n-ans<<"\n";
	// while(p>0){
	// 	if(tcnt>=2){
	// 		p -= (l + 2*t);
	// 		tcnt-=2;
	// 	} else if(tcnt==1){
	// 		p -= (l + t);
	// 		tcnt-=1;
	// 	} else {
	// 		p-= (l);
	// 	}
	// 	ans++;
	// }
	// cout<<n-ans<<"\n";
}
	return 0;
}