#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int gcd(int x, int y){
	if(y%x==0){
		return x;
	}
	return gcd(y%x, x);
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int x;
	cin>>x;
	int y;
	cin>>y;
	int nbyx = n/x;
	int nbyy = n/y;
	int gcdxy = gcd(x,y);
	int unimp = (n*gcdxy)/(x*y);
	int ximp = nbyx - unimp;
	int yimp = nbyy - unimp;
	int ans = 0;
	ans += (((n*(n+1))/2) - (((n-ximp)*((n-ximp)+1))/2));
	// for(int i = 0; i<ximp; i++){
	// 	ans += n-i;
	// }
	ans -= (yimp*(yimp+1))/2;
	// for(int i = 1; i<=yimp; i++){
	// 	ans -= i;
	// }
	cout<<ans<<"\n";
}
	return 0;
}