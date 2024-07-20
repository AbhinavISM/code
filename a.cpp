#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
void dfs(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &dp){
    dp[node] = node+1;
    for(ll child : adj[node]){
        if(child!=par){
            dfs(child, node, adj, dp);
            dp[node] += dp[child];
        }
    }
}
long long minDiff(int n, int a[], int b[]){
    if(n==1) {
        cout<<1;
        return 0;
    }
    vector<vector<ll>> adj(n, vector<ll>());
    for(ll i = 0; i<n-1; i++){
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    vector<ll> dp(n,0);
    dfs(0,-1,adj,dp);
    ll total = n;
    total = total*(n+1);
    total = total/2;
    ll ans = INT_MAX;
    for(ll i = 1; i<n; i++){
        ans = min(ans, abs(total - dp[i] - dp[i]));
    }
    cout<<ans;
}
int main(){
    fast_io;
    ll n;
    cin>>n;
    int a[n-1];
    int b[n-1];
    // vector<ll> a(n-1,0);
    for(ll i = 0; i<n-1; i++){
        cin>>a[i];
        a[i]--;
    }
    // vector<ll> b(n-1,0);
    for(ll i = 0; i<n-1; i++){
        cin>>b[i];
        b[i]--;
    }
    minDiff(n,a,b);
    // if(n==1) {
    //     cout<<1;
    //     return 0;
    // }
    // vector<vector<ll>> adj(n, vector<ll>());
    // for(ll i = 0; i<n-1; i++){
    //     adj[a[i]].push_back(b[i]);
    //     adj[b[i]].push_back(a[i]);
    // }
    // vector<ll> dp(n,0);
    // dfs(0,-1,adj,dp);
    // ll total = (n*(n+1))/2;
    // ll ans = INT_MAX;
    // for(ll i = 1; i<n; i++){
    //     ans = min(ans, abs(total - dp[i] - dp[i]));
    // }
    // cout<<ans;
}