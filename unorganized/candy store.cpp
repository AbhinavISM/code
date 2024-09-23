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
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
		cin>>b[i];
	}
	int ans = 1;
	int abgcd = a[0]*b[0];
	int blcm = b[0];
	for(int i = 1; i<n; i++){
		abgcd = __gcd(abgcd, a[i]*b[i]);
		blcm = (blcm*b[i])/(__gcd(blcm,b[i]));
		if(abgcd%blcm!=0){
			abgcd = a[i]*b[i];
			blcm = b[i];
			ans++;
			i--;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}