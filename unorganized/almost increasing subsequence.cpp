#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	vector<int> dp(n+1,0);
	dp[1] = 1;
	int lastval = 1;
	for(int i = 2; i<=n; i++){
		if(a[i]<=a[i-1]) {dp[i] = -1;}
		if(a[i]>a[i-1]) {
			int j = i-1;
			while(dp[j]==-1){
				dp[j] = lastval+1;
				j--;
			}
			dp[i] = dp[i-1] + 1;
			lastval = dp[i];
		}
	}
	if(dp[n]==-1){
		int j = n;
		while(dp[j]==-1){
			dp[j] = lastval+1;
			j--;
		}
	}
	// peek(dp)
	set<int> ans;
	for(int i = 1; i<=n; i++){
		ans.insert(dp[i]);
		dp[i] = ans.size();
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(r-l+1<=2){
			cout<<r-l+1<<"\n";
			continue;
		}
		if(dp[l-1]==dp[l+1]){
			cout<<dp[r] - dp[l-1] + 2<<"\n";
			continue;
		}
		if(dp[l]==dp[l-1]||dp[l]==dp[l+1]){
			cout<<dp[r] - dp[l-1] + 1<<"\n";
			continue;
		}
		cout<<dp[r] - dp[l-1]<<"\n";
	}
}