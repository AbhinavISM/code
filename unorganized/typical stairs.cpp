#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int m;
	cin>>m;
	set<int> broken;
	for(int i = 1; i<=m; i++){
		int item;
		cin>>item;
		broken.insert(item);
	}
	vector<int> dp(n+1,0);
	dp[0] = 1;
	if(broken.find(1)!=broken.end()){
		dp[1] = 0;
	} else {
		dp[1] = 1;
	}
	for(int i = 2; i<=n; i++){
		if(broken.find(i)==broken.end()){
			dp[i] = (dp[i-1] + dp[i-2])%1000000007;
		} else {
			dp[i] = 0;
		}
	}
	cout<<dp[n];
	return 0;
}