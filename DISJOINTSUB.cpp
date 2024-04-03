#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
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
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	bool good = true;
	for(int i = 1; i<n-1; i++){
		if(a[i-1]>a[i]&&a[i]>a[i+1]){
			good = false;
		}
	}
	if(!good){
		cout<<"No\n";
		return 0;
	}
	int l = INT_MIN;
	int r = INT_MAX;
	for(int i = 1; i<n; i++){
		if(a[i]<a[i-1]) {
			l = max(l,a[i-1]-a[i]);
			if(i+1<n) r = min(r,a[i+1]-a[i]);
		}
	}
	// cout<<l<<" "<<r<<"\n";
	if(l<=r) cout<<"Yes\n";
	else cout<<"No\n";
}
	return 0;
}