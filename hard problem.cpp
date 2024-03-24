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
	vector<string> strings(n);
	for(int i = 0; i<n; i++){
		cin>>strings[i];
	}
	int INF = 1e15;
	vector<vector<int>> dp(n, vector<int>(2,INF));
	dp[0][0] = 0;
	dp[0][1] = array[0];
	for(int i = 1; i<n; i++){
		if(strings[i]>=strings[i-1]){
			// if(i==2){cout<<"aye";}
			dp[i][0] = min(dp[i][0], dp[i-1][0]);
		}
		reverse(strings[i-1].begin(), strings[i-1].end());
		if(strings[i]>=strings[i-1]){
			dp[i][0] = min(dp[i][0], dp[i-1][1]);
		}
		reverse(strings[i].begin(), strings[i].end());
		if(strings[i]>=strings[i-1]){
			dp[i][1] = min(dp[i][1], dp[i-1][1] + array[i]);
		}
		reverse(strings[i-1].begin(), strings[i-1].end());
		if(strings[i]>=strings[i-1]){
			dp[i][1] = min(dp[i][1], dp[i-1][0] + array[i]);
		}
		reverse(strings[i].begin(), strings[i].end());
		// cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
	}
	int ans = min(dp[n-1][0], dp[n-1][1]);
	if(ans==INF){
		cout<<-1;
	} else {
		cout<<ans;
	}
	return 0;
}