#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m,d;
	cin>>n>>m>>d;
	vector<int> cs;
	cs.push_back(1);
	bool one = false;
	for(int i = 1; i<=m; i++){
		int item;
		cin>>item;
		if(item!=1) cs.push_back(item);
		else one = true;
	}
	vector<int> dp(cs.size());
	for(int i = 0; i<dp.size(); i++){
		if(i!=dp.size()-1)dp[i] = 1 + ((cs[i+1]-cs[i]-1)/d);
		else dp[i] = 1 + ((n-cs[i])/d);
	}
	map<int,int> impact;
	if(one){impact[0]++;}
	for(int i = dp.size()-1; i>=1; i--){
		if(i==dp.size()-1){
			int goodness = dp[i-1]+dp[i]-(((n-cs[i-1])/d) + 1);
			impact[goodness]++;
		} else {
			int goodness = dp[i-1]+dp[i]-(((cs[i+1]-cs[i-1]-1)/d) + 1);
			impact[goodness]++;
		}
	}

	int dpsum = 0;
	for(int i = 0; i<dp.size(); i++){
		dpsum += dp[i];
	}
	auto ans = impact.rbegin();
	cout<<dpsum-(*ans).first<<" "<<(*ans).second<<"\n";
}
	return 0;
}