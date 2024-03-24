#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i : v) {for(auto j : i){ if(j.second!=INT64_MAX)cout<<j.second<<" ";else cout<<-1<<" ";} cout<<"\n";}
using namespace std;
void dp_solution(){
	int t;
	cin>>t;
	while(t--){
	int n,l;
	cin>>n>>l;
	vector<pair<int,int>> a(n+1);
	for(int i = 1; i<=n; i++){
		cin>>a[i].first>>a[i].second;
	}
	vector<vector<pair<int,int>>> dp(n+2, vector<pair<int,int>>(n+2,{-1,0}));
	for(int i = 1; i<=n+1; i++){
		dp[n+1][i] = {-1,INT64_MAX};
	}
	int ans = 0;
	for(int i = n; i>=1; i--){
		for(int j = 1; j<=n; j++){
			int c1 = dp[i+1][j].second;
			int c2;
			if(dp[i+1][j-1].second==INT64_MAX){
				c2 = INT64_MAX;
			} else {
				if(dp[i+1][j-1].first!=-1){
					c2 =  abs(dp[i+1][j-1].first - a[i].second) + dp[i+1][j-1].second + a[i].first;
				} else {
					c2 = a[i].first;
				}
			}
			if(c1<=c2){
				dp[i][j].second = c1;
				dp[i][j].first = dp[i+1][j].first;
			} else {
				dp[i][j].second = c2;
				dp[i][j].first = a[i].second;
			}
			//calculate ans
			if(dp[i][j].second<=l){
				ans = max(ans,j);
			}
		}
	}
	// dpeek(dp)
	cout<<ans<<"\n";
}
}

int32_t main(){
	fast_io;
	// dp_solution();
	int t;
	cin>>t;
	while(t--){
	int n,l;
	cin>>n>>l;
	vector<pair<int,int>> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i].second>>a[i].first;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i<n; i++){
		multiset<int> ms;
		int total = 0;
		for(int j = i; j<n; j++){
			total += a[j].second;
			ms.insert(a[j].second);
			while(total+ a[j].first - a[i].first > l && ms.size()!=0){
				total -= *(--ms.end());
				ms.erase((--ms.end()));
			}
			ans = max(ans, (int)ms.size());
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}