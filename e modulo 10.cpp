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
	bool fiveorzero = false;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		if(a[i]%10==0||a[i]%10==5){
			fiveorzero = true;
		}
	}
	if(fiveorzero){
		for(int i = 0; i<n; i++){
			if(a[i]%10==5) a[i]+=5;
		}
		bool ans = true;
		int last = a[0];
		for(int i = 1; i<n; i++){
			if(a[i]!=last) ans = false;
			last = a[i];
		}
		if(ans){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		continue;
	}
	for(int i = 0; i<n; i++){
		while(a[i]%10!=2){
			a[i] += a[i]%10;
		}
	}
	bool ans = true;
	int last = a[0];
	for(int i = 0; i<n; i++){
		if(abs(a[i]-a[0])%20!=0){
			ans = false;
			break;
		}
	}
	if(ans){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}