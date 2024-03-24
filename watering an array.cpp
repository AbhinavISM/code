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
	int n,k,d;
	cin>>n>>k>>d;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> v(k);
	vector<int> inc(n+1,0);
	vector<pair<int,vector<int>>> firstocc(n,{INT64_MAX,vector<int>()});
	for(int i = 0; i<k; i++){
		int item;
		cin>>item;
		v[i] = item;
		inc[item]--;
		inc[0]++;
		if(firstocc[item-1].first==INT64_MAX){
			firstocc[item-1].first = i;
			firstocc[item-1].second = inc;
		}
	}
	for(int i = n-2; i>=0; i--){
		if(firstocc[i].first>firstocc[i+1].first){
			firstocc[i].second = firstocc[i+1].second;
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 1; j<=n; j++){
			if(firstocc[i].first!=INT64_MAX)
			firstocc[i].second[j] += firstocc[i].second[j-1];
		}
	}
	for(int i = 1; i<=n; i++){
		inc[i] += inc[i-1];
	}
	peek(inc)
}
	return 0;
}