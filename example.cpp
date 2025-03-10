#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t -- ){
		int k, l1, r1, l2, r2;
		cin >> k >> l1 >> r1 >> l2 >> r2;
		int kpow = 1;
		int ans = 0;
		for( int n = 0 ; true ; n ++ ) {
			int lo = l1;
			int hi = r1;
			int ans1 = INT64_MIN;
			while (hi >= lo) {
				int mid = lo + ( hi - lo ) / 2;
				if( mid * kpow <= r2 ) {
					lo = mid + 1;
					ans1 = max( ans1 , mid );
				} else {
					hi = mid - 1;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}