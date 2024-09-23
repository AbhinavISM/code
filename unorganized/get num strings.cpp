#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
vector<int> getNumStrings(int k, vector<vector<int>> query){
	int mod = 1000000007;
	vector<int> dp(100001,0);
	for(int i = 0; i<k; i++){
		dp[i] = 1;
	}
	for(int i = k; i<100001; i++){
		dp[i] = (dp[i-1]+dp[i-k])%mod;
	}
	for(int i = 1; i<100001; i++){
		dp[i] = (dp[i]+dp[i-1])%mod;
	}
	vector<int> ans;
	for(vector<int> q : query){
		int l = q[0];
		int r = q[1];
		ans.push_back(dp[r] - dp[l-1]);
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n,k;
	cin>>n>>k;
	vector<vector<int>> query(n,vector<int>(2));
	for(int i = 0; i<n; i++){
		cin>>query[i][0]>>query[i][1];
	}
	peek(getNumStrings(k,query));
}