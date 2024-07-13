#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

vector<vector<int>> dp,dp2;
int solve(int n,int k,vector<int> &v){
	if(k==0 || n==0) return 0;
	if(dp[n][k]!=-1) return dp[n][k];
	int ans=0;
	ans=max(solve(n-1,k,v),solve(n-1,k-1,v) | v[n-1]);
	return dp[n][k]=ans;
}
int solve2(int n,int k,vector<int> &v){
	if(k==0 || n==0) return 0;
	if(dp2[n][k]!=-1) return dp2[n][k];
	int ans=0;
	ans=max(solve2(n-1,k,v),solve2(n-1,k-1,v) | v[n-1]);
	return dp2[n][k]=ans;
}
int32_t main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    dp.resize(n+1,vector<int>(k+1,-1));
    for(int i=0;i<n;i++) cin>>v[i];
    // reverse(v.begin(),v.end());
    for(int i=0;i<=n;i++){
    	solve(i,k,v);
    }
    reverse(v.begin(),v.end());
    
    dp2.resize(n+1,vector<int>(k+1,-1));
    for(int i=n;i>=0;i--){
    	solve2(i,k,v);
    }
    
    int ans=0;
    for(int i=k;i<=n-k;i++){
    	ans=max(ans,dp[i][k] ^ dp2[n-i][k]);
    }
    cout<<ans<<endl;
    return 0;
}