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
	vector<int> a(2*n);
	for(int i = 0; i<2*n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	sort(a.begin(), a.end(), greater<int>());
	int ans = 0;
	// peek(a);
	for(int i = 0; i<2*n; i+=2){
		if(i+1<2*n) ans += a[i+1];
	}
	cout<<ans<<"\n";
}
	return 0;
}