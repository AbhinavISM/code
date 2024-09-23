#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int solve(vector<int> &a, int &n, int i, int j, bool turn, vector<vector<vector<int>>> &dp){
	if(i>j) return 0;
	if(dp[i][j][turn]!=-1) return dp[i][j][turn];
	if(turn){
		int a1 = a[i] + solve(a,n,i+1,j,false,dp);
		int a2 = a[j] + solve(a,n,i,j-1,false,dp);
		return dp[i][j][turn] = max(a1,a2);
	} else {
		int a1 = solve(a,n,i+1,j,true,dp) - a[i];
		int a2 = solve(a,n,i,j-1,true,dp) - a[j];
		return dp[i][j][turn] = min(a1,a2);
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
	cout<<solve(a,n,0,n-1,true,dp);
}