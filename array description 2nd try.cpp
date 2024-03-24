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
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<vector<int>> dp(n, vector<int>(m,0));
	if(array[0]==0){
		for(int i = 0; i<m; i++){
			dp[0][i] = 1;
		}
	} else {
		dp[0][array[0]] = 1;
	}
	for(int i = 1; i<n; i++){
		if(array[i]==0){
			for(int j = 0; j<m; j++){
				dp[i][j] = (j==0?0:dp[i-1][j-1]) + dp[i-1][j] + (j==m-1?0:dp[i-1][j+1]);
				dp[i][j]%=1000000007;
			}
		} else {
			dp[i][array[i]] = (array[i]==0?0:dp[i-1][array[i]-1]) + dp[i-1][array[i]] + (array[i]==m-1?0:dp[i-1][array[i]+1]);
			dp[i][array[i]]%=1000000007;
		}
	}
	int ans = 0;
	for(int i = 0; i<m; i++){
		ans += dp[n-1][i];
		ans %= 1000000007;
	}
	cout<<ans;
	return 0;
}