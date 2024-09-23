#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;

int32_t main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int>> dp(k+1, vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i<=k; i++){
        for(int j = 1; j<=n; j++){
            if(dp[i-1][j]>=1){
                for(int k = j; k<=n; k+=j){
                    dp[i][k] += dp[i-1][j];
                    dp[i][k] %= 1000000007;
                }
            }
        }
    }
    int mod = 1000000007;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum=(sum+dp[k][i])%mod;
    }
    cout<<sum%mod<<endl;
    // cout<<accumulate(dp[k].begin(), dp[k].end(),0)%1000000007;
    return 0;
}