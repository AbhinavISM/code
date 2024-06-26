#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int mod = 1000000007;
class Solution {
public:
	int rec(int hat, int mask, vector<vector<int>>& hats, vector<vector<int>> &dp, int &n){
		if(hat==40){
			if(mask==(1<<n)-1) return 1;
			else return 0;
		}
		if(dp[hat][mask]!=-1) return dp[hat][mask];
		int ans = 0;
		for(int i = 0; i<n; i++){
			if(mask&(1<<i)) continue;
			for(int j : hats[i]){
				if(j==hat) ans = (ans + rec(hat+1,mask|(1<<hat),hats,dp,n))%mod;
			}
		}
		return dp[hat][mask] = ans;
	}
    int numberWays(vector<vector<int>>& hats) {
    	int n = hats.size();
        vector<vector<int>> dp(40, vector<int>(n,-1));
        return rec(0,0,hats,dp,n);
    }
};

int32_t main(){
	fast_io;
}