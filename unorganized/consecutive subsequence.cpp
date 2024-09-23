#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> dp(n);
	map<int,int> largestidx;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		largestidx[item] = i;
		a[i] = item;
		if(largestidx.find(item-1)==largestidx.end()){
			dp[i] = 1;
		} else {
			dp[i] = 1 + dp[largestidx[item-1]];
		}
	}
	int maxlen = 0;
	int maxidx;
	for(int i = 0; i<n; i++){
		if(dp[i]>maxlen){
			maxlen = dp[i];
			maxidx = i;
		}
	}
	set<int> ans;
	ans.insert(maxidx);
	int tofind = a[maxidx] - 1;
	for(int i = maxidx-1; i>=0; i--){
		if(a[i]==tofind){
			ans.insert(i);
			tofind--;
		}
	}
	cout<<maxlen<<"\n";
	for(int z : ans){
		cout<<z+1<<" ";
	}
	return 0;
}