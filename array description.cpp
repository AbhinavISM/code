#include<bits/stdc++.h>
// #define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
    fast_io;
    int mod = 1000000007;
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> array(n+1,0);
    for(int i = 1; i<=n; i++){
        int item;
        cin>>item;
        array[i] = item;
    }
    vector<vector<int>> dp(n+1, vector<int>(m+2,0));
    if(array[1]==0){
        for(int i = 1; i<=m; i++){
            dp[1][i] = 1;
        }
    } else {
        dp[1][array[1]] = 1;
    }
    for(int i = 2; i<=n; i++){
        if(array[i]==0){
            for(int j = 1; j<=m; j++){
                dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j+1])%mod + dp[i-1][j])%mod;
            }
        } else {
            dp[i][array[i]] = ((dp[i-1][array[i] - 1] + dp[i-1][array[i] + 1])%mod + dp[i-1][array[i]])%mod;
        }
    }
    int ans = 0;
    for(int i = 1; i<=m; i++){
        ans += dp[n][i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}