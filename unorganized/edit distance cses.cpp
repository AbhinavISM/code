#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;

int32_t main() {
    string n;
    cin>>n;
    string m;
    cin>>m;
    std::vector<std::vector<int>> dp(n.length()+1, std::vector<int>(m.length()+1,0));
    // cout<<solve(dp,a,b);
    int a = n.length();
    int b = m.length();
    //ORDER OF THESE NESTED LOOPS DOES NOT EVEN MATTER
    for(int j = 0; j<=b; j++){
        for(int i = 0; i<=a; i++){
            if(i==0){
                dp[i][j] = j;
            } else if(j==0){
                dp[i][j] = i;
            } else if(n[i-1]==m[j-1]){
                dp[i][j] = min({dp[i-1][j-1], dp[i][j-1] + 1, dp[i-1][j] + 1});
            } else {
                dp[i][j] = min({dp[i-1][j-1] + 1, dp[i][j-1] + 1, dp[i-1][j] + 1});
            }
        }
    }
    cout<<dp[a][b];
    return 0;
}