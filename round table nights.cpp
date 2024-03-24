#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> mood(n);
	for(int i = 0; i<n; i++){
		cin>>mood[i];
	}	
	vector<pair<int,int>> div;
	div.push_back({1,1});
	for(int i = 2; i*i<=n; i++){
		if(n%i==0){
			div.push_back({i,1});
			if(i*i!=n){
				div.push_back({n/i,1});				
			}
		}
	}
	vector<vector<pair<int,int>>> dp(n);
	for(int i = 0; i<n; i++){
		dp[i] = div;
	}
	// if(mood[0]==0){
	// 	for(int i = 0; i<div.size(); i++){
	// 		dp[0][i].second = -1;
	// 	}
	// }
	for(int i = 1; i<n; i++){
		if(mood[i]==1){
			for(int j = 0; j<div.size(); j++){
				if(i-div[j].first>=0&&mood[i-div[j].first]==1){
					dp[i][j].second += dp[i - div[j].first][j].second;			
				}
				if((dp[i][j].second==(n/dp[i][j].first))&&dp[i][j].second>=3){
					// cout<<dp[i][j].first<<" "<<dp[i][j].second<<" ";
					cout<<"YES\n";
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
	// for(int i = 0; i<n; i++){
	// 	for(int j = 0; j<div.size(); j++){
	// 		cout<<dp[i][j].first<<" "<<dp[i][j].second<<"\n";
	// 	}
	// 	cout<<"\n";
	// }
	
	return 0;
}