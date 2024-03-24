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
	int sum = 0;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		v[i] = item;
	}
	sort(v.begin(), v.end(), greater<int>());
	vector<int> prefix(n,0);
	prefix[0] = v[0];
	for(int i = 1; i<n; i++){
		prefix[i] = prefix[i-1] + v[i];
	}
	// for(int i = 0; i<n; i++){
	// 	cout<<prefix[i]<<" ";
	// }
	// cout<<"\n";
	int maxi = INT_MIN;
	// cout<<prefix[n-1-2*k]<<" ";
	maxi = max(maxi, prefix[n-1-2*k]);
	for(int i = 1; i<=k; i++){
		maxi = max(maxi, prefix[n-1-2*(k-i)] - prefix[i-1]);
		// cout<<prefix[n-1-2*(k-i)] - prefix[i-1]<<" ";
	}
	// cout<<"\n";
	cout<<maxi<<"\n";
}
	return 0;
}