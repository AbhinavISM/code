#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int binsrch(int a, int x){
	int lo = 1;
	int hi = 10000;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int ans = a*a*a + mid*mid*mid;
		
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int x;
	cin>>x;
	int lo = 1;
	int hi = 10000;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int ans = binsrch(mid, x);
	}
}
	return 0;
}