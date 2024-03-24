#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll mod=1e9+7; 
 
ll binexp(ll a,ll b){
ll res =1;
while(b>0){
if(b&1){res = (res*a)%mod;}
a = (a*a)%mod;b>>=1;
}return res;}
                   
int main(){
ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 ll n,m;
 cin>>n>>m;
 vector<ll>v(n+1);
 for(int i=1;i<=n;i++){
    cin>>v[i];
 }
 vector<vector<ll>>dp(n+1,vector<ll>(m+2,0));
    for(int j=1;j<=m;j++){
        if(j==v[1] || v[1]==0){
            dp[1][j] =1;
        }
        else{
            dp[1][j] =0;
        }
    }
for(int i=2;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(v[i]!=0 && j!=v[i]){
            dp[i][j] =0;
        }
        else{
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
        }
    }
}
// for(int i=1;i<=n;i++){
//     for(int j=1;j<=m;j++){
//      cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
// }
ll ans =0;
for(int i=1;i<=m;i++){
  ans=(ans+dp[n][i])%mod;
}
cout<<ans<<endl;
}