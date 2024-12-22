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
	int m;
	cin>>m;
	vector<int> a(n);
	for(int i = 1; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	a[0] = 1;
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int hi = n;
	int lo = 0;
	int ans = INT_MAX;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		bool good = true;
		for(int i = 0; i<n-mid; i++){
			if(b[i+mid]<=a[i]){good = false;}
		}
		if(good){
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout<<ans<<"\n";

}
	return 0;
}