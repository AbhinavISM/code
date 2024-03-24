#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> b(n+1);
	//way 1
	// map<int,vector<int>> viplusi;
	// for(int i = 1; i<=n; i++){
	// 	int item;
	// 	cin>>item;
	// 	b[i] = item;
	// 	if(viplusi.find(i+item)!=viplusi.end()){
	// 		viplusi[i+item].push_back(i);
	// 	} else {
	// 		viplusi[i+item] = vector<int>();
	// 		viplusi[i+item].push_back(i);
	// 	}
	// }
	// vector<int> dp(n+1,0);
	// dp[0] = 0;
	// for(int i = 1; i<=n; i++){
	// 	dp[i] = dp[i-1] + 1;
	// 	for(int it : viplusi[i]){
	// 		dp[i] = min(dp[i], dp[it-1]);
	// 	}
	// }
	// cout<<dp[n]<<"\n";

	//way2
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	vector<int> dp(n+1,INT64_MAX);
	dp[0] = 0;
	for(int i = 1; i<=n; i++){
		dp[i] = min(dp[i-1] + 1, dp[i]);
		if(i+b[i]<=n) dp[i+b[i]] = min(dp[i+b[i]], dp[i-1]);
	}
	cout<<dp[n]<<"\n";
}
	return 0;
}