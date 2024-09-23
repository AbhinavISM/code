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
	int n,f,a,b;
	cin>>n>>f>>a>>b;
	vector<int> m(n+1,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		m[i] = item;
	}
	vector<int> dp(n+1,0);
	dp[0] = f;
	for(int i = 1; i<=n; i++){
		dp[i] = max(dp[i-1]-(m[i]-m[i-1])*a, dp[i-1] - b);
	}
	if(dp[n]>0) cout<<"YES\n";
	else cout<<"NO\n";
}
	return 0;
}