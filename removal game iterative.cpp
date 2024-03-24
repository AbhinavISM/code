#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n+1);
	vector<int> prefix(n+1,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
		prefix[i] = prefix[i-1] + item;
	}
	vector<vector<int>> dp(n+2, vector<int>(n+2,0));
	for(int i = n; i>=1; i--){
		for(int j = 1; j<=n; j++){
			if(i<=j){
				dp[i][j] = max(array[i] + prefix[j] - prefix[i] - dp[i+1][j], array[j] + prefix[j-1] - prefix[i-1] - dp[i][j-1]);				
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}