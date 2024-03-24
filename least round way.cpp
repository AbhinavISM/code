#include<bits/stdc++.h>
// #define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<pair<int,int>>> a(n,vector<pair<int,int>>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			int val;
			cin>>val;
			a[i][j] = {0,0};
			while(val%2==0){
				a[i][j].first++;
				val/=2;
			}
			while(val%5==0){
				a[i][j].second++;
				val/=5;
			}
		}
	}
	vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(i==0&&j==0){
				dp[i][j] = a[i][j];
				continue;
			}
			dp[i][j] = {INT64_MAX, INT64_MAX};
			if(i-1>=0){
				dp[i][j] = {a[i][j].first+a[i-1][j].first, a[i][j].second+a[i-1][j].second};
			}
			if(j-1>=0){
				if(min(dp[i][j].first, dp[i][j].second)>min(a[i][j].first+a[i][j-1].first,a[i][j].second+a[i][j-1].second)){
					dp[i][j] = {a[i][j].first+a[i][j-1].first,a[i][j].second+a[i][j-1].second};
				}
			}
		}
	}
	cout<<min(dp[n-1][n-1].first, dp[n-1][n-1].second)<<"\n";
	return 0;
}