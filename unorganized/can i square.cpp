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
	int sum = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		sum+=item;
	}
	bool ans = false;
	int lo =1 ;
	int hi = 20000000;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(mid*mid==sum){
			ans = true;
			break;
		} else if(mid*mid>sum){
			hi = mid-1;
		} else {
			lo = mid+1;
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