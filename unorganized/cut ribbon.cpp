#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	vector<int> dp(n+1,-1);
	dp[0] = 0;
	for(int i = 1; i<=n; i++){
		int x = (i-a<0?-1:(dp[i-a]>-1?(dp[i-a]+1):dp[i-a]));
		int y = (i-b<0?-1:(dp[i-b]>-1?(dp[i-b]+1):dp[i-b]));
		int z = (i-c<0?-1:(dp[i-c]>-1?(dp[i-c]+1):dp[i-c]));
		dp[i]=max({x,y,z});
	}
	cout<<dp[n];
	return 0;
}