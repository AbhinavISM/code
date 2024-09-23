#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct pts {
	int a;
	int b;
	int c;
};
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<pts> array(n, pts());
	for(int i = 0; i<n; i++){
		int a, b, c;
		cin>>array[i].a>>array[i].b>>array[i].c;
	}
	vector<vector<int>> dp(n, vector<int>(3,0));
	dp[0][0] = array[0].a;
	dp[0][1] = array[0].b;
	dp[0][2] = array[0].c;
	for(int i = 1; i<n; i++){
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + array[i].a;
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + array[i].b;
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + array[i].c;
	}
	cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	return 0;
}