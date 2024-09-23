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
	int n;
	cin>>n;
	int ans;
	int hi = 10000000000;
	int lo = 1;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int combs = (mid*(mid-1))/2;
		if(combs == n){
			ans = mid;
			break;
		}
		else if(combs>n){
			hi = mid - 1;
		} else {
			ans = mid;
			lo = mid + 1;
		}
	}
	if(hi>=lo){
		cout<<ans<<"\n";
	} else {
		ans += (n - (ans*(ans-1))/2);
		cout<<ans<<"\n";
	}
}
	return 0;
}