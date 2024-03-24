#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int i,j;
	for(i = 0; i<n; i++){
		if(s[i]=='1'){
			break;
		}
	}
	for(j = n-1; j>=0; j--){
		if(s[j]=='1'){
			break;
		}
	}
	// cout<<i<<" "<<j<<"\n";
	if(i==n){
		cout<<0<<"\n";
		continue;
	}
	vector<int> onecnt(n,0);
	onecnt[i] = 1;
	for(int x = i+1; x<=j; x++){
		onecnt[x] = onecnt[x-1];
		if(s[x]=='1') {
			onecnt[x]++;
		}
	}
	// peek(onecnt)
	vector<vector<int>> dp(n,vector<int>(2,0));
	for(int x = i; x<=j; x++){
		if(x-k<i){
			dp[x][0] = onecnt[x];
			if(x-1>=0) dp[x][1] = onecnt[x-1];
			if(s[x]=='0'){
				dp[x][1]++;
			}
		} else {
			dp[x][0] = onecnt[x];
			dp[x][1] = onecnt[x-1] - onecnt[x-k];
			dp[x][1] += min(dp[x-k][1], dp[x-k][0]);
			if(s[x]=='0'){
				dp[x][1]++;
			}
		}
	}
	// peek(dp)
	cout<<min(dp[j][0], dp[j][1])<<"\n";
}
	return 0;
}