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
	int n,k;
	cin>>n>>k;
	vector<int> danger(n+1,0);
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<int> x(n);
	for(int i = 0; i<n; i++){
		cin>>x[i];
		danger[abs(x[i])] += a[i];
	}
	int left = 0;
	bool good = true;
	for(int i = 1; i<=n; i++){
		danger[i] -= (k + left);
		if(danger[i]>0){
			good = false;
		} else {
			left = abs(danger[i]);
		}
	}
	if(good){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}