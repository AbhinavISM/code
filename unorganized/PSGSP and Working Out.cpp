#include<bits/stdc++.h>
#define int long long
#define itn long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> matrix(n+2,vector<int>(m+2,0));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>matrix[i][j];
		}
	}
	vector<vector<int>> dp1(n+2,vector<int>(m+2,0));
	vector<vector<int>> dp2(n+2,vector<int>(m+2,0));
	vector<vector<int>> dp3(n+2,vector<int>(m+2,0));
	vector<vector<int>> dp4(n+2,vector<int>(m+2,0));

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]);
			dp1[i][j] += matrix[i][j];
		}
	}
	for(int i = n; i>=1; i--){
		for(int j = 1; j<=m; j++){
			dp2[i][j] = max(dp2[i+1][j],dp2[i][j-1]);
			dp2[i][j] += matrix[i][j];
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = m; j>=1; j--){
			dp3[i][j] = max(dp3[i-1][j],dp3[i][j+1]);
			dp3[i][j] += matrix[i][j];
		}
	}
	for(int i = n; i>=1; i--){
		for(int j = m; j>=1; j--){
			dp4[i][j] = max(dp4[i+1][j],dp4[i][j+1]);
			dp4[i][j] += matrix[i][j];
		}
	}
	// dpeek(dp1)
	// dpeek(dp2)
	// dpeek(dp3)
	// dpeek(dp4)
	int ans = 0;
	for(int i = 2; i<n; i++){
		for(int j = 2; j<m; j++){
			int gain1 = dp1[i-1][j] + dp4[i+1][j] + dp2[i][j-1] + dp3[i][j+1];
			int gain2 = dp1[i][j-1] + dp4[i][j+1] + dp2[i+1][j] + dp3[i-1][j];
			ans = max({ans,gain1,gain2});
			// if(ans==max(gain1, gain2)){
			// 	cout<<i<<" "<<j<<"\n";
			// }
		}
	}
	cout<<ans<<"\n";
	return 0;
}