#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<pair<int,int>> array(n);
	for(int i = 0; i<n; i++){
		int l,r;
		cin>>l>>r;
		array[i] = {l,r};
	}
	int hi = 1e9;
	int lo = 0;
	int ans;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int l = 0;
		int r = 0;
		int good = true;
		for(int i = 0; i<n; i++){
			r = min(r + mid, array[i].second);
			l = max(l - mid, array[i].first);
			if(l>r){
				good = false;
				break;
			}
		}
		if(good){
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}