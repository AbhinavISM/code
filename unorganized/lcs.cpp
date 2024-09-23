#include<bits/stdc++.h>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

int32_t main(){
	fast_io;
	string text1;
	cin>>text1;
	string text2;
	cin>>text2;
	int n = text1.size();
    int m = text2.size();
    int dp[n+1][m+1];
    for(int i = 0; i<=m; i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i<=n; i++){
    	for(int j = 1; j<=m; j++){
    		if(text1[i-1]==text2[j-1]){
    			dp[i][j] = max({dp[i-1][j-1] + 1, dp[i-1][j], dp[i][j-1]});
    		} else {
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }
    cout<<dp[n][m];
}