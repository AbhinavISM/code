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
	int last = n-1;
	bool ans = true;
	for(int i = 0; i<n&&i<k; i++){
		if(a[last]<=n){
			last = ((last-a[last] + n)%n);				
		} else {
			ans = false;
			break;
		}
	}
	if(ans){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}