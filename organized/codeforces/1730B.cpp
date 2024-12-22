#include<bits/stdc++.h>
using namespace std;

pair<bool, double> check(vector<int> &x, vector<int> &t, int n, double mid){
	double maxl = -1e9;
	double minr = 1e9;
	for (int i = 0; i < n; i++) {
        maxl = max(maxl, x[i] - mid + t[i]);
        minr = min(minr, x[i] + mid - t[i]);
    }
    return {maxl<=minr, maxl};
}
int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> x(n);
		for(int i = 0; i<n; i++){
			cin>>x[i];
		}
		vector<int> t(n);
		for(int i = 0; i<n; i++){
			cin>>t[i];	
		}
		double lo = 0;
		double hi = 1e9;
		double ans;
		while(abs(hi-lo)>=(1e-6)){
			double mid = lo + (hi-lo)/2;
			pair<bool, double> res = check(x,t,n,mid);
			if(res.first){
				ans = res.second;
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << fixed << setprecision(7) << ans << endl;
	}
	return 0;
}