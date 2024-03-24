#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> h(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		h[i] = item;
	}
	vector<int> t(m);
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		t[i] = item;
	}
	int fans = INT_MIN;
	for(int i = 0; i<n; i++){
		int hi = 1e18;
		int lo = 0;
		int ans = INT_MAX;
		while(hi>=lo){
			int mid = lo + (hi-lo)/2;
			int l = h[i] - mid;
			int r = h[i] + mid;
			auto it1 = lower_bound(t.begin(), t.end(), l);
			auto it2 = upper_bound(t.begin(), t.end(), r);
			if(it1==it2){
				lo = mid + 1;
			} else {
				ans = min(ans, mid);
				hi = mid - 1;
			}
		}
		// cout<<ans<<" ";
		fans = max(ans,fans);
	}
	cout<<fans;
	return 0;
}