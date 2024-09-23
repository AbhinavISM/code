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
	int total = 0;
	int add = 0;
	vector<int> a(n+1);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		total+=a[i];
		add += a[i]*a[i];
	}
	vector<int> b(n+1);
	for(int i = 1; i<=n; i++){
		cin>>b[i];
		total+=b[i];
		add += b[i]*b[i];
	}
	add *= (n-2);
	vector<vector<int>> dp(10001, vector<int>(n+1,0));
	dp[0][0] = 1;
	for(int sum = 0; sum<=10000; sum++){
		for(int i = 1; i<=n; i++){
			if(sum-a[i]>=0) dp[sum][i] = dp[sum-a[i]][i-1];
			if(sum-b[i]>=0) dp[sum][i] = max(dp[sum-b[i]][i-1], dp[sum][i]);
		}
	}
	int ans = INT64_MAX;
	for(int sum = 0; sum<=10000; sum++){
		if(dp[sum][n]>0){
			int asum = sum;
			int bsum = (total-sum);
			ans = min(asum*asum + bsum*bsum, ans);
		}
	}
	cout<<ans + add<<"\n";
}
	return 0;
}