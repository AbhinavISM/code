#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int m,x;
	cin>>m>>x;
	vector<int> c(m,0);
	vector<int> h(m,0);
	int sumh = 0;
	for(int i = 0; i<m; i++){
		cin>>c[i]>>h[i];
		sumh += h[i];
	}
	vector<int> dp(sumh+1,1e10);
	dp[0] = 0;
	for(int i = 0; i<m; i++){
		for(int j = sumh; j>=0; j--){
			if(j-h[i]>=0&&dp[j-h[i]]+c[i]<=(i)*x) dp[j] = min(dp[j],dp[j-h[i]]+c[i]);
		}
	}
	for(int i = sumh; i>=0; i--){
		if(dp[i]!=1e10) {
			cout<<i<<"\n";
			break;
		}
	}
}
	return 0;
}