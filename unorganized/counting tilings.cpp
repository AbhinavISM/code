#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define pb push_back
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
void generateNextMasks(int idx, int oldMask, int newMask, vector<int> &nextMasks, int &n, int &m){
	if(idx==n) {
		nextMasks.pb(newMask);
		return;
	}
	if(oldMask&(1<<idx)) generateNextMasks(idx+1,oldMask,newMask,nextMasks,n,m);
	if((oldMask&(1<<idx))==0){
		generateNextMasks(idx+1,oldMask|(1<<idx),newMask|(1<<idx),nextMasks,n,m);
		if(idx!=n-1&&(oldMask&(1<<(idx+1)))==0) generateNextMasks(idx+2,(oldMask|(1<<idx))|(1<<(idx+1)),newMask,nextMasks,n,m);
	}
}
int solve(int idx, int mask, int &n, int &m, vector<vector<int>> &dp){
	if(idx==m) {
		if(mask==0) return 1;
		else return 0;
	}
	if(dp[idx][mask]!=-1) return dp[idx][mask];
	vector<int> nextMasks;
	generateNextMasks(0, mask, 0, nextMasks, n, m);
	int ans = 0;
	for(int nextMask : nextMasks){
		ans += solve(idx+1,nextMask,n,m,dp);
		ans %= 1000000007;
	}
	return dp[idx][mask] = ans;
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> dp(m, vector<int>(1<<n,-1));
	cout<<solve(0,0,n,m,dp);
}