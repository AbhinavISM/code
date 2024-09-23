#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define mod 1000000007
// int cal(vector<pair<int,int>>& books,int i,int w,vector<vector<int>>&dp){
//     if(i==books.size()) return 0;
//     if(dp[i][w]!=-1) return dp[i][w];
//     int take =0,notake;
//     notake = cal(books,i+1,w,dp);
//     if(w>=books[i].first){
//         take = cal(books,i+1,w-books[i].first,dp) + books[i].second;
//     }
//     else return dp[i][w] = 0;
//     return dp[i][w] = max(notake,take);
// }
void solve(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> books(n);
    for(auto &i:books) cin>>i.first;
    for(auto &i:books) cin>>i.second;
    // sort(books.begin(), books.end()); 
    vector<vector<int>>  dp(n+1,vector<int>(x+1,0));
    // cout<<cal(books,0,x,dp)<<endl;
    for(int j=1;j<=n;j++){
        for(int i =1;i<=x;i++) {
        dp[j][i] = dp[j-1][i];
            if(i>=books[j-1].first){
              dp[j][i] = max(dp[j][i] , dp[j-1][i-books[j-1].first]+books[j-1].second);  
            }
        }
    }
    cout<<dp[n][x];
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}