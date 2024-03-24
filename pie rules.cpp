#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n+1,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> prefix(n+1,0);
	for(int i = 1; i<=n; i++){
		prefix[i] += prefix[i-1];
		prefix[i] += array[i];
	}
	vector<int> dp(n+2,0);
	for(int i = n; i>=1; i--){
		dp[i] = max(array[i] + prefix[n] - prefix[i] - dp[i+1], dp[i+1]);
	}
	cout<<prefix[n] - prefix[0] - dp[1]<<" "<<dp[1];
	return 0;
}