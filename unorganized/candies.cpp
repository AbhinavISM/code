#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int eatcandies(int n, int k){
	int eaten = 0;
	while(n>0){
		if(n>=k){
			eaten += k;
			n -= k;	
		} else {
			eaten += n;
			n = 0;
		}
		if(n>=10){
			n = n - n/10;
		}
	}
	return eaten;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int hi = n;
	int lo = 1;
	int ans = INT64_MAX;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int candieseaten = eatcandies(n,mid);
		if(candieseaten>=(n+1)/2){
			ans = min(ans, mid);
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	cout<<ans;
	return 0;
}