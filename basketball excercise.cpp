#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	int dp[n][2];
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	int max0 = a[0];
	int max1 = b[0];
	for(int i = 1; i<n; i++){
		dp[i][0] = max1 + a[i];
		dp[i][1] = max0 + b[i];
		max0 = max(max0, dp[i][0]);
		max1 = max(max1, dp[i][1]);
	}
	cout<<max(dp[n-1][0], dp[n-1][1]);
	return 0;
}