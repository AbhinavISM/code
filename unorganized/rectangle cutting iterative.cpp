#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int a,b;
	cin>>a>>b;
	vector<vector<int>> dp(a+1, vector<int>(b+1,INT64_MAX));
	for(int i = 1; i<=a; i++){
		for(int j = 1; j<=b; j++){
			if(i==j){
				dp[i][j] = 0;
			}
		}
	}
	for(int i = 1; i<=a; i++){
		for(int j = 1; j<=b; j++){
			if(i!=j){
				for(int k = 1; k<i; k++){
					dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
				}
				for(int k = 1; k<j; k++){
					dp[i][j] = min(dp[i][j],  dp[i][j-k] + dp[i][k] + 1);
				}
			}
		}
	}
	cout<<dp[a][b];

	return 0;
}