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
	int n,m,k;
	cin>>n>>m>>k ;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<int> d(m);
	for(int i = 0; i<m; i++){
		cin>>d[i];
	}
	vector<int> f(k);
	for(int i = 0; i<k; i++){
		cin>>f[i];
	}
	sort(a.begin(), a.end());
	sort(d.begin(), d.end());
	sort(f.begin(), f.end());
	int maxdiff = INT64_MIN;
	int secmaxdiff = INT64_MIN;
	int maxidx = -1;
	for(int i = 1; i<n; i++){
		int diff = a[i] - a[i-1];
		if(diff>=maxdiff){
			secmaxdiff = maxdiff;
			maxdiff = diff;
			maxidx = i;
		} else if(diff>secmaxdiff){
			secmaxdiff = diff;
		}
	}
	// cout<<maxdiff<<" "<<secmaxdiff<<"\n";
	int ans = INT64_MAX;
	for(int i = 0; i<m; i++){
		auto lb = lower_bound(f.begin(), f.end(), (a[maxidx] + a[maxidx-1])/2 - d[i]);
		if(lb!=f.end()) {
			ans = min(ans, max(a[maxidx] - d[i] - *lb, d[i] + *lb - a[maxidx-1]));
		}
		if(lb!=f.begin()){
			lb--;
			ans = min(ans, max(a[maxidx] - d[i] - *lb, d[i] + *lb - a[maxidx-1]));
			lb++;
		}
		if(lb!=f.end()&&(++lb)!=f.end()){
			ans = min(ans, max(a[maxidx] - d[i] - *lb, d[i] + *lb - a[maxidx-1]));
		}
	}
	// cout<<ans<<"\n";
	cout<<min(maxdiff, max(ans, secmaxdiff))<<"\n";
}
	return 0;
}