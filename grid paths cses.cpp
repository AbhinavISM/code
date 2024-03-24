#include<bits/stdc++.h>
// #define int long long
#define ld long double
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<pair<int,int>> books(n);
    for(auto &it : books){
        cin>>it.first;
    }
    for(auto &it : books){
        cin>>it.second;
    }
    vector<vector<int>> dp(x+1,vector<int>(n+1,0));
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=x; j++){
             if(books[i-1].first<=j){
                dp[j][i] = max(dp[j-books[i-1].first][i-1]+ books[i-1].second, dp[j][i-1]);
                continue;
            }
            dp[j][i] = dp[j][i-1];
        }
    }
    cout<<dp[x][n]<<" ";
    return 0;
}
