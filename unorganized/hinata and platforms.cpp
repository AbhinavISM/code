#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	vector<int> x(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		x[i] = item;
	}
	vector<int> y(n);
	for(int i = 0; i<n; i++){
		cin>>y[i];
	}
	sort(x.begin(), x.end());
	vector<int> captured(n,0);
	vector<int> nextmax(n,0);
	for(int i = 0; i<n; i++){
		auto ub = upper_bound(x.begin(), x.end(), x[i] + k);
		int next = (ub-x.begin());
		ub--;
		captured[i] = (ub-x.begin() + 1) - i;
		if(next<n) nextmax[next] = max(nextmax[next], (ub-x.begin() + 1) - i);
	}
	for(int i =  1; i<n; i++){
		nextmax[i] = max(nextmax[i], nextmax[i-1]);
	}
	int ans = 0;
	for(int i =  0; i<n; i++){
		ans = max(ans, nextmax[i] + captured[i]);
	}
	cout<<ans<<"\n";
}
	return 0;
}