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
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	bool good = true;
	for(int i = 1; i<n-1; i++){
		a[i] -= a[i-1]*2;
		a[i+1] -= a[i-1];
		a[i-1] = 0;
		if(a[i]<0||a[i+1]<0){
			good = false;
		}
	}
	if(a[n-2]!=0||a[n-1]!=0){
		good = false;
	}
	if(good){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}