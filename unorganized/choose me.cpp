#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int aoki = 0;
	int takahashi = 0;
	vector<pair<int,int>> vs(n);
	for(int i = 0; i<n; i++){
		int ai;
		cin>>ai;
		int ti;
		cin>>ti;
		aoki += ai;
		vs[i].first = 2*ai+ti;
		vs[i].second = ai;
	}
	sort(vs.begin(), vs.end());
	int ans = 0;
	for(int i = n-1; i>=0&&aoki>=takahashi; i--){
		ans += 1;
		aoki -= vs[i].second;
		takahashi += (vs[i].first-vs[i].second);
	}
	cout<<ans<<"\n";
	return 0;
}