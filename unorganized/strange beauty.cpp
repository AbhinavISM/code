#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	vector<vector<int>> divisors(200001, vector<int>());
	while(t--){
	int n;
	cin>>n;
	vector<int> freq(200001);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		freq[item]++;
	}
	vector<int> dp(200001,0);
	for(int i = 1; i<200001; i++){
		if(freq[i]==0){continue;}
		if(divisors[i].size()==0){
			for(int d = 1; d*d<=i; d++){
				if(i%d==0){
					divisors[i].push_back(d);
				}
			}
		}
		for(int d : divisors[i]){
			dp[i] = max(dp[i], dp[d] + freq[i]);
			if(d!=1)dp[i] = max(dp[i], dp[i/d] + freq[i]);
		}
	}
	int maxsize = 0;
	for(int i = 0; i<200001; i++){
		maxsize = max(maxsize, dp[i]);
	}
	cout<<n-maxsize<<"\n";
}
	return 0;
}