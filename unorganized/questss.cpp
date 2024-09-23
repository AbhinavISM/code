#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,c,d;
	cin>>n>>c>>d;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	sort(a.begin(), a.end(), greater<int>());
	int val = 0;
	for(int i = 0; i<n&&i<d; i++){
		val += a[i];
	}
	if(val>=c){
		cout<<"Infinity\n";
		continue;
	}
	int hi = d;
	int lo = 0;
	int ans = INT64_MIN;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int sum = 0;
		int factor = 1;
		for(int i = 0; i<d; ){
			for(int j = 0; j<=mid&&j<n&&i<d; j++){
				sum += a[j];
				i++;
			}
			i = (mid+1)*factor;
			factor++;
		}
		if(sum>=c){
			lo = mid + 1;
			ans = max(ans, mid);
		} else {
			hi = mid - 1;
		}
	}
	if(ans==INT64_MIN){
		cout<<"Impossible\n";
	} else {
		cout<<ans<<"\n";
	}
}
	return 0;
}