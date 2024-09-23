#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
long getMaxScore(int n, vector<vector<int>> score){
	vector<vector<int>> dp(n, vector<int>(10,0));
	for (int i = 1; i<n; ++i) {
	    for (int j = 0; j < 10; ++j) {
	        for (int k = 0; k < 10; ++k) {
	            dp[i][j] = max(dp[i][j], dp[i-1][k] + score[k][j]);
	        }
	    }
	}
	int ans = 0;
	for (int j = 0; j<10; ++j) {
	    ans = max(ans, dp[n-1][j]);
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> score(10,vector<int>(10));
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			cin>>score[i][j];
		}
	}
	cout<<getMaxScore(n, score);
}