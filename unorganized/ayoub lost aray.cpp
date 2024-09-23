#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int MOD = 1000000007;
int32_t main() {
    int n;
    cin>>n;
    int l;
    cin>>l;
    int r;
    cin>>r;
    int n0 = floor(r/3.0)-ceil(l/3.0)+1;
    int n1 = (floor((r-1)/3.0)-ceil((l-1)/3.0)+1);
    int n2 = (floor((r-2)/3.0)-ceil((l-2)/3.0)+1);
    vector<vector<int>> dp(n+1, vector<int>(3,-1));
    dp[1][0] = n0;
    dp[1][1] = n1;
    dp[1][2] = n2;
    for(int i =2; i<=n; i++){
        dp[i][0] = (dp[i-1][0]*n0+dp[i-1][1]*n2+dp[i-1][2]*n1)%MOD;
        dp[i][1] = (dp[i-1][0]*n1+dp[i-1][1]*n0+dp[i-1][2]*n2)%MOD;
        dp[i][2] = (dp[i-1][0]*n2+dp[i-1][1]*n1+dp[i-1][2]*n0)%MOD;
    }
    cout<<dp[n][0];
    return 0;
}