#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;

int32_t main(){
	fast_io;
	int n,m,c0,d0;
	cin>>n>>m>>c0>>d0;
	vector<int> a(m+1);
	vector<int> b(m+1);
	vector<int> c(m+1);
	vector<int> d(m+1);
	for(int i = 1; i<=m; i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	a[0] = 100;
	b[0] = 0;
	c[0] = c0;
	d[0] = d0;
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(101,0)));
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=m; j++){
			for(int k = 1; k<=100; k++){
				if(j==0&&i-c0>=0){
					dp[i][j][k] = max(dp[i][j][k], dp[i-c0][j][k] + d0);
				}
				 if(i-c[j]>=0&&k-b[i]>=0){
					dp[i][j][k] = max(dp[i][j][k], dp[i-c[j]][j][k-b[j]] + d[j]);				
				}
				for(int l = 0; l<=m; l++){
					if(l!=j&&i-c[j]>=0){
						dp[i][j][k] = max(dp[i][j][k], dp[i-c[j]][l][k] + d[j]);
					}
				}
			}
		}
	}
	int ans = dp[n][0][100];
	for(int i = 1; i<=m; i++){
		ans = max(ans,dp[n][i][a[i]]);
	}
	cout<<ans<<"\n";
}