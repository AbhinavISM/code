#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	int k;
	cin>>k;
	vector<int> dp(100001,0);
	for(int i = 1; i<k; i++){
		dp[i] = 1;
	}
	dp[k] = 2;
	for(int i = k+1; i <= 100000; i++){
		dp[i] = dp[i-k] + dp[i-1];
		dp[i]%=1000000007;
	}
	vector<int> prefix(100001,0);
	for(int i = 1; i<=100000; i++){
		prefix[i] = prefix[i-1] + dp[i];
		prefix[i]%=1000000007;
	}
	while(t--){
		int a;
		int b;
		cin>>a;
		cin>>b;
		cout<<(prefix[b]-prefix[a-1]+1000000007)%1000000007<<"\n";
		}
	return 0;
}