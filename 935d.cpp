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
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<int> b(n+1,0);
	for(int i = 0; i<n; i++){
		cin>>b[i];
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<int> ans(n+1,0);
	ans[1] = a[1];
	for(int i = 2; i<=n; i++){
		ans[i] = ans[i-1] - a[i-1] + min(a[i-1],b[i-1]) + a[i];
	}
	// peek(a)
	// peek(b)
	// peek(ans)
	int fans = INT64_MAX;
	for(int i = n-m+1; i<=n; i++){
		if(n-m+1>0) fans = min(fans, ans[i]);
	}
	cout<<fans<<"\n";
}
	return 0;
}