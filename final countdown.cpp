#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> dp(n+1,0);
	for(int i = 1; i<=n; i++){
		dp[i] = dp[i-1] + ((int)s[i-1]-48);
	}
	// peek(dp)
	for(int i = n-1; i>=1; i--){
		int j = i;
		int tmp = dp[i];
		dp[i] = 0;
		while(tmp!=0){
			dp[j] += tmp%10;
			tmp = tmp/10;
			j--;
		}
	}
	dp.erase(--dp.end());
	// peek(dp)
	vector<int> ans(n+1);
	for(int i = n; i>=1; i--){
		ans[i] = (dp[i-1] + (s[i-1] - 48)); 
	}
	// peek(ans)
	for(int i = n; i>=1; i--){
		int j = i;
		int tmp = ans[i];
		ans[i] = 0;
		while(tmp!=0){
			ans[j] += tmp%10;
			tmp = tmp/10;
			j--;
		}
	}
	// peek(ans)
	vector<int> fans;
	int actual = -1;
	for(int i = 0; i<ans.size(); i++){
		if(ans[i]!=0){
			actual = i;
			break;
		}
	}
	for(int i = actual; i<ans.size(); i++){
		fans.push_back(ans[i]);
	}
	peek(fans)
	// // for(int i = ans.size()-1; i>=0; i--){
	// // 	int j = i;
	// // 	int tmp = ans[i];
	// // 	ans[i] = 0;
	// // 	while(tmp!=0){
	// // 		ans[j] += tmp%10;
	// // 		tmp = tmp/10;
	// // 		j--;
	// // 	}
	// // }
	// peek(ans)
}
	return 0;
}