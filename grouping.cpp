#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(vector<int> &dp, int &n, int mask, vector<vector<int>> &array){
	if(mask<=0){
		return 0;
	}
	if(dp[mask]!=INT64_MIN){
		return dp[mask];
	}
	for(int x=mask; x>0; x = (x-1) & mask){
		if(x==mask){continue;}
		vector<int> rabbits;
		int rabbitPower = 0;
		for(int i = 0; i<n; i++){
			if((!(x&(1<<i)))&(mask&(1<<i)) != 0){
				rabbits.push_back(i);
			}
		}
		for(int i = 0; i<rabbits.size(); i++){
			for(int j = i+1; j<rabbits.size(); j++){
				rabbitPower += array[rabbits[i]][rabbits[j]];
			}
		}
		dp[mask] = max(dp[mask], solve(dp,n,x,array) + rabbitPower);
	}
	int x = 0;
	vector<int> rabbits;
	int rabbitPower = 0;
	for(int i = 0; i<n; i++){
		if((!(x&(1<<i)))&(mask&(1<<i)) != 0){
			rabbits.push_back(i);
		}
	}
	for(int i = 0; i<rabbits.size(); i++){
		for(int j = i+1; j<rabbits.size(); j++){
			rabbitPower += array[rabbits[i]][rabbits[j]];
		}
	}
	
	dp[mask] = max(dp[mask], solve(dp,n,x,array) + rabbitPower);
	return dp[mask];
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> array(n,vector<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			int item;
			cin>>item;
			array[i][j] = item;
		}
	}
	vector<int> dp(1<<n, INT64_MIN);
	int ans = solve(dp,n,(1<<n)-1,array);
	cout<<ans<<"\n";	
	return 0;
}