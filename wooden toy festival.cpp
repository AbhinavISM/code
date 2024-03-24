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
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	sort(a.begin(), a.end());
	int ans;
	int lo = 0;
	int hi = 1e9;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int i;
		int j;
		for(i = 0; i<n&&a[i]-a[0]<=2*mid; i++){}
		for(j = n-1; j>=0&&a[n-1]-a[j]<=2*mid; j--){}
		if(i>j || a[j]-a[i]<=2*mid){
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}