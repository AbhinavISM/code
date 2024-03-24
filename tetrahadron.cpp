#include<bits/stdc++.h>
// #define int long long
#define ld long double
using namespace std;

int32_t main() {
    int n;
    cin>>n;
    vector<vector<int>> dp(2, vector<int>(4,0));

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j<=3; j++){
            for(int k = 0; k<=3; k++){
                if(k!=j){
                    dp[1][j] += dp[0][k];
                    dp[1][j] %= 1000000007;
                }
            }
        }
        for(int i = 0; i<=3; i++){
            dp[0][i] = dp[1][i];
            dp[1][i] = 0;
        }
    }
    cout<<dp[0][3];
    return 0;
}