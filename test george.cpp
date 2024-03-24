#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int m;
	cin>>m;
	int k;
	cin>>k;
	// vector<int> array(n+1);
	vector<int> pre(n+1, 0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		// array[i] = item;
		pre[i] = pre[i-1] + item;
	}
	// cout<<pre[n]<<" ";
	vector<vector<int>> dp(k+1, vector<int>(n+1,0));
	dp[1][m] = pre[m];
	for(int i = 1; i<=k; i++){
		for(int j = i*m; j<=n; j++){
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-m]+pre[j]-pre[j-m]);
		}
	}
	cout<<dp[k][n];
	return 0;
}