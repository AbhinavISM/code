#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int mod = 1e9+7;
int32_t main(){
	fast_io;
	string s;
	int d;
	cin>>s;
	cin>>d;
	vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(d, vector<int>(2,0)));
	for(int i=0; i<(s[0] - '0'); i++){
		dp[0][i%d][0]++;
	}
	dp[0][(s[0] - '0') % d][1]++;
	for(int i=1; i<s.size(); i++){
		for(int j=0; j<d; j++){
			for(int k=0; k<2; k++){
				if(k == 0){
					for(int digit = 0; digit<10; digit++){
						dp[i][(j+digit)%d][0] += dp[i-1][j][0];
						dp[i][(j+digit)%d][0] %= mod;
					}
				}
				else{
					for(int digit=0; digit<(s[i] - '0'); digit++){
						dp[i][(j+digit)%d][0] += dp[i-1][j][1];
						dp[i][(j+digit)%d][0] %= mod;
					}
					dp[i][(j+(s[i]-'0'))%d][1] += dp[i-1][j][1];
					dp[i][(j+(s[i] - '0'))%d][1] %= mod;
				}
			}
		}
	}
	int ans = (dp[s.size()-1][0][0] + dp[s.size()-1][0][1] - 1 + mod) % mod;
	cout<<ans<<endl;
}