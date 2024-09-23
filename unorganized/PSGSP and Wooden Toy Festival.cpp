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
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	sort(a.begin(), a.end());
	int hi = 1e9;
	int lo = 0;
	int ans = INT64_MAX;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int i = 0;
		for(i = 0; i<n&&a[i] - a[0]<=2*mid; i++){}
		int j = n-1;
		for(j = n-1; j>=0&&a[n-1] - a[j]<=2*mid; j--){}
		if(j<i||a[j] - a[i] <= 2*mid){
			hi = mid - 1;
			ans = min(ans,mid);
		} else {
			lo = mid + 1;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}