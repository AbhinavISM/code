#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int solve(vector<vector<int>> &dp, int a, int b){
    if(a==b){
        return 0;
    }
    // if(a<=0||b<=0){
    //     return INT_MAX;
    // }
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    int ans = INT_MAX;
    for(int i = 1; i<=a/2; i++){
        ans = min(ans, solve(dp, i, b)+solve(dp,a-i,b));
    }
    for(int i = 1; i<=b/2; i++){
        ans = min(ans, solve(dp, a, i)+solve(dp,a,b-i));
    }
    return dp[a][b] = ans +1;
}
int32_t main() {
    int a;
    cin>>a;
    int b;
    cin>>b;
    std::vector<std::vector<int>> dp(a+1, std::vector<int>(b+1,-1));
    cout<<solve(dp,a,b);
    
    return 0;
}