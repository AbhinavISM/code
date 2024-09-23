#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(vector<int> &array, vector<vector<int>> &links, vector<int> &dp, int i, int &n, int aya){
	if(dp[i]!=-1){
		return dp[i];
	}
	for(int link : links[i]){
		if(link != aya){
			int result = solve(array, links, dp, link, n, i);
			if(result==0){
				dp[i] = 1;
				return dp[i];
			}		
		}
	}
	dp[i] = 0;
	return dp[i];
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<vector<int>> links(n+1,vector<int>());
	for(int i = 1; i<=n; i++){
		int j = i + array[i];
		while(j<=n){
			if(array[j]>array[i]){
				links[i].push_back(j);
			}
			j += array[i];
		}
		j = i - array[i];
		while(j>=1){
			if(array[j]>array[i]){
				links[i].push_back(j);
			}
			j -= array[i];
		}
	}
	vector<int> dp(n+1,-1);
	for(int i = 1; i<=n; i++){
		if(links[i].size()==0){
			dp[i] = 0;
		}
	}
	for(int i = 1; i<=n; i++){
		int alice = solve(array, links, dp, i, n, i);
		if(alice==1){
			cout<<'A';
		} else {
			cout<<'B';
		}
	}
	
	return 0;
}