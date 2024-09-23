#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<vector<bool>> dp(n,vector<bool>(100001,false));
	for(int i = n-1; i>=0; i--){
		dp[i][array[i]] = true;
		dp[i][0] = true;
		for(int j = 1; j<=100000; j++){
			if(j-array[i]>=0&&i+1<n)dp[i][j] = dp[i][j]||dp[i+1][j-array[i]];
			if(i+1<n)dp[i][j] = dp[i][j]||dp[i+1][j];
		}
	}
	int ans = 0;
	for(int i = 1; i<=100000; i++){
		if(dp[0][i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	for(int i = 1; i<=100000; i++){
		if(dp[0][i]){
			cout<<i<<" ";
		}
	}
	cout<<"\n";
	return 0;
}