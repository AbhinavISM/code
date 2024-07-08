#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int solve(int x, int y, int z, int m, vector<int> &a, vector<vector<vector<int>>> &dp){
    if(y==0&&z==0) return 0;
    if(y==0||x==0) return -1;
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    if(y==1){
    	return dp[x][y][z];
        // int sum = 0;
        // for(int i = 1; i<=x; i++) if(a[i]%m==z) dp[x][y][z] = max(dp[x][y][z], a[i]);
    }
    
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    if(solve(x-1,y-1,((z-a[x])%m + m)%m,m,a,dp)!=-1) return dp[x][y][z] = max(solve(x-1,y-1,((z-a[x])%m + m)%m,m,a,dp) + a[x], solve(x-1,y,z,m,a,dp));
    else return dp[x][y][z] = solve(x-1,y,z,m,a,dp);
}
int32_t main(){
    fast_io;
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> a(n+1,0);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(m+1,-1)));
    for(int x=1; x<=n; x++){
        for(int z=0; z<m; z++){
        	dp[x][1][z] = max(dp[x][1][z], dp[x-1][1][z]);
        	if(a[x]%m == z){
        		dp[x][1][z] = max(dp[x][1][z], a[x]);
        	}
        }
    }
    cout<<solve(n,k,0,m,a,dp);
}