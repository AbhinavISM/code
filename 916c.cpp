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
	int k;
	cin>>k;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	int ans = 0;
	int sum = 0;
	int maxb = 0;
	for(int i = 0; i<n&&i<k; i++){
		sum += a[i];
		maxb = max(maxb, b[i]);
		// if(i<k){
			ans = max(sum + (k-i-1)*maxb, ans);
		// }
		// cout<<ans<<" ";
	}
	cout<<ans<<"\n";
}
	return 0;
}