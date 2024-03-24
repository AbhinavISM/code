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
	int n,k,x;
	cin>>n>>k>>x;
	vector<int> a(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	sort(a.begin(), a.end());
	vector<int> pre(n+1,0);
	for(int i = 1; i<=n; i++){
		pre[i] = pre[i-1] + a[i];
	}
	int neg, pos;
	int ans = INT64_MIN;
	// peek(pre);
	for(int i = 0; i<=k; i++){
		if(n-x-i>=0){
			// cout<<"heh";
			neg = pre[n-i]-pre[n-x-i];
			pos = pre[n-x-i];
		} else {
			// cout<<"meh";
			neg = pre[n-i];
			pos = 0;
		}
		// cout<<pos<<" "<<neg<<"\n";
		ans = max(ans, pos-neg);
	}
	cout<<ans<<"\n";
}
	return 0;
}