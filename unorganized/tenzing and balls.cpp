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
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> dp(n,0);
	map<int,vector<int>> f;
	map<int, int> g;
	f[array[0]] = vector<int>();
	f[array[0]].push_back(0);
	g[array[0]] = max(g[array[0]],dp[0] - 0 + 1);
	for(int j = 1; j<n; j++){
		if(f.find(array[j])==f.end()){
			f[array[j]] = vector<int>();
			f[array[j]].push_back(j);
			dp[j] = dp[j-1];
			g[array[j]] = dp[j-1] - j + 1;
		} else {
			int maxi = 0;
			// for(int i : f[array[j]]){
			// 	maxi = max(maxi, (((i!=0)?dp[i-1]:0) + j-i+1));
			// }
			maxi = g[array[j]];
			maxi += j;
			dp[j] = max(maxi, dp[j-1]);
			f[array[j]].push_back(j);
			g[array[j]] = max(g[array[j]] ,dp[j-1] - j + 1);
		}
	}
	cout<<dp[n-1]<<"\n";
}
	return 0;
}