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
	int a;
	cin>>a;
	int b;
	cin>>b;
	int c;
	cin>>c;
	int gcdbc = gcd(b,c);
	int finalgcd = gcd(a, gcdbc);
	int cnt = 0;
	int q = (a/finalgcd);
	int w = (b/finalgcd);
	int e = (c/finalgcd);
	q--;
	w--;
	e--;
	cnt = q+w+e;
	// cout<<finalgcd<<" "<<cnt<<" "<<e<<" ";
	if(cnt<=3){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}