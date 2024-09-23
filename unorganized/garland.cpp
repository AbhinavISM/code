#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int MOD = 1000000007;

int solve(int evencount, int oddcount, int previous, int i, vector<int> &garland,vector<vector<vector<vector<int>>>> &dp){
	if(i==garland.size()){
		return 0;
	}
	// if(previous!=-1)
	// cout<<dp[i][evencount][oddcount][previous]<<"\n";
	if(dp[i][evencount][oddcount][previous] != -1&&previous!=-1){
		return dp[i][evencount][oddcount][previous];
	}
	if(garland[i]==0){
		if(previous==0){
		return dp[i][evencount][oddcount][previous] = min(((evencount==0) ? INT_MAX : solve(evencount-1,oddcount,0,i+1,garland,dp)),
		 ((oddcount==0)? INT_MAX :solve(evencount, oddcount-1,1,i+1,garland,dp)+1));
		} else if(previous==1){
			return dp[i][evencount][oddcount][previous] = min(((evencount==0) ? INT_MAX : solve(evencount-1,oddcount,0,i+1,garland,dp)+1),
		 ((oddcount==0)? INT_MAX :solve(evencount, oddcount-1,1,i+1,garland,dp)));
		} else {
			return dp[i][evencount][oddcount][previous] = min(((evencount==0) ? INT_MAX : solve(evencount-1,oddcount,0,i+1,garland,dp)),
		 ((oddcount==0)? INT_MAX :solve(evencount, oddcount-1,1,i+1,garland,dp)));
		}
	}

	if((previous==0||previous==-1)&&garland[i]%2==0){
		return dp[i][evencount][oddcount][previous] = solve(evencount,oddcount,0,i+1,garland,dp);
	} else if((previous==1||previous==-1)&&garland[i]%2==1){
		return dp[i][evencount][oddcount][previous] = solve(evencount,oddcount,1,i+1,garland,dp);
	} else {
		return dp[i][evencount][oddcount][previous] = solve(evencount,oddcount,garland[i]%2,i+1,garland,dp)+1;
	}
}
int32_t main() {
	int n;
	cin>>n;
	vector<int> garland(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		garland[i] = item;
	}
	// vector<vector<int>> dp(n+1, vector<int>(n+1,0));
	vector<bool> isgayab(n+1,1);
	// base case
	for(int i = 1; i<=n; i++){
		isgayab[garland[i]] = 0; 
	}
	vector<int> onlygayab;
	int oddcount = 0;
	int evencount = 0;
	for(int i = 1; i<=n; i++){
		if(isgayab[i]){
			if(i%2==1){
				oddcount++;
			}else{
				evencount++;
			}
			onlygayab.push_back(i);
			// cout<<i<<" ";
		}
	}
	vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1,vector<vector<int>>(n+1,vector<int>(2,-1))));
	cout<<solve(evencount,oddcount,-1,1,garland,dp);
}