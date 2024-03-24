#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

int solve(int l, int r, int k, int sum, int m, int n, vector<int> &array,vector<vector<int>> &dp){
	if(r>n&&k>0){
		return 0;
	}
	if(k==0){
		return sum;
	}
	if(dp[l][k]!=-1){
		return dp[l][k];
	}
	int partSum = 0;
	for(int i = l; i<=r; i++){
		partSum += array[i];
	}

	return dp[l][k] = max(solve(r+1,r+m,k-1,sum+partSum,m,n,array,dp), solve(l+1,r+1,k,sum,m,n,array,dp));
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int m;
	cin>>m;
	int k;
	cin>>k;
	vector<int> array(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
	cout<<solve(1,m,k,0,m,n,array,dp);
	return 0;
}