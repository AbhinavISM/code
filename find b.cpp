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
	int n,q;
	cin>>n>>q;
	vector<int> c(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		c[i] = item;
	}
	vector<int> onecnt(n+1,0);
	vector<int> prefix(n+1,0);
	for(int i = 1; i<=n; i++){
		if(c[i-1]==1){
			onecnt[i] = onecnt[i-1] + 1;
		} else {
			onecnt[i] = onecnt[i-1];
		}
	}
	for(int i = 1; i<=n; i++){
		prefix[i] = prefix[i-1] + c[i-1];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(l==r){
			cout<<"NO\n";
		} else if(onecnt[r] - onecnt[l-1] == 0){
			cout<<"YES\n";
		} else {
			int sum = prefix[r] - prefix[l-1];
			int ones = onecnt[r] - onecnt[l-1];
			int non_ones = (r-l+1) - ones;
			sum -= non_ones;
			if((sum/ones)>1){
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}
}
	return 0;
}