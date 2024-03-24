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
	int n;
	cin>>n;
	vector<int> p(2*n);
	for(int i = 0; i<2*n; i++){
		cin>>p[i];
	}
	sort(p.begin(), p.end());
	int ans = INT64_MAX;
	int ans2 = 0;
	int ans3 = 0;
	if(n==1){
		int ans = 0;
		for(int i = 1; i<2*n; i++){
			ans += abs(p[i]-p[0]);
		}
		cout<<ans<<"\n";
		continue;
	}
	if(n%2){
		int ans = 0;
		for(int i = 0; i<2*n; i++){
			ans += abs(p[i]);
		}
		cout<<ans<<"\n";
		continue;
	}
	if(n==2){
		ans = 0;
		for(int i = 0; i<2*n; i++){
			ans += abs(p[i]-2);
		}
	}
	for(int i = 0; i<2*n-1; i++){
		ans2 += abs(p[i]+1);
		ans3 += abs(p[i]);
	}
	ans2 += abs(p[2*n-1] - n);
	ans3 += abs(p[2*n-1]);
	cout<<min({ans, ans2, ans3})<<"\n";
}
	return 0;
}