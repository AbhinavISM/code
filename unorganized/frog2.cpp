#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<int> array(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> dp(n+1,0);
	for(int i = 2; i<=n; i++){
		int mini = INT_MAX;
		for(int j = 1; j<=k; j++){
			if(i-j>0){
				mini = min(mini, abs(array[i] - array[i-j]) + dp[i-j]);
			}
		}
		dp[i] = mini;
	}
	cout<<dp[n];
	return 0;
}