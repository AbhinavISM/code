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
	int n;
	cin>>n;
	int zerocnt = 0;
	vector<int> c;
	c.push_back(0);
	int last=0;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i<n; i++){
		int item = a[i];
		if(item==last){
			c[item]++;
		} else if(item==last+1){
			c.push_back(1);
			last = item;
		}
	}
	if(c[0]==0){
		cout<<0<<"\n";
		continue;
	}
	vector<int> dp(c.size());
	for(int i = c.size()-1; i>=0; i--){
		int mex = c.size();
		dp[i] = (c[i]-1)*mex + i;
		for(int j = i+1; j<c.size(); j++){
			dp[i] = min(dp[i], dp[j] + (c[i]-1)*j + i);
		}
	}
	cout<<dp[0]<<"\n";
}
	return 0;
}