#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	int maxleft = 1;
	vector<int> dp(n,1);
	for(int i = 0; i<n; i++){
		if(i==0){
			dp[0] = 1;
			continue;
		}
		if(array[i]<=array[i-1]){
			maxleft = 1;
		} else {
			maxleft++;
		}
		dp[i] = maxleft;
		// dp[i]--;
	}
	vector<int> oneidx;
	for(int i = 1; i<n; i++){
		if(dp[i]==1){
			oneidx.push_back(i);
		}
	}
	int ans = 0;
	for(int i=0; i<oneidx.size(); i++){
		if(array[oneidx[i]-1] - array[oneidx[i]]>=2){
			if(i!=oneidx.size()-1) ans = max(ans, dp[oneidx[i]-1]+dp[oneidx[i+1]-1]);
			else if(oneidx[i]!=n-1) ans = max(ans, dp[oneidx[i]-1] + dp[n-1]);
			else max(ans, dp[oneidx[i]-1] + 1);
		} else {
			ans = max(ans, dp[oneidx[i]-1] + 1);
		}
	}
		cout<<ans;

	// for(int i : dp){
	// 	cout<<i<<" ";
	// }
	// cout<<"\n";
	return 0;
}