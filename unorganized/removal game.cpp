#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(int s, int e, vector<int> &scores, vector<vector<int>> &dp){
	if(s>e){
		return 0;
	}
	if(dp[s][e]!=-1){
		return dp[s][e];
	}
	int op1 = scores[e]+ min(solve(s+1,e-1,scores,dp),solve(s,e-2,scores,dp));
	int op2 = scores[s]+ min(solve(s+1,e-1,scores,dp),solve(s+2,e,scores,dp));
	return dp[s][e]=max(op1,op2);
	// else	
	// return min(dp[e][1], dp[e][0]);
}
int32_t main(){
	fast_io;
	int n;
    cin>>n;
    vector<int> scores(n);
	vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
	vector<int> totalsum;
    for(int i = 0; i<n; i++){
    	int item;
    	cin>>item;
    	scores[i] = item;
    }
    cout<<solve(0,n-1,scores,dp);
}