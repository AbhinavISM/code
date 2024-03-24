#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	string s;
	cin>>s;
	int n = s.length();
	for(int i = 0; i<n; i++){
		if(s[i]=='m'||s[i]=='w'){
			cout<<0;
			return 0;
		}
	}
	vector<int> dp(n+1,0);
	dp[0] = 1;
	dp[1] = 1;
	char last = s[0];
	for(int i = 2; i<=n; i++){
		if(last==s[i-1]&&(last=='u'||last=='n')){
			dp[i] = (dp[i-1] + dp[i-2])%1000000007;
		} else {
			dp[i] = dp[i-1];
		}
		last = s[i-1];
	}
	cout<<dp[n];
	return 0;
}