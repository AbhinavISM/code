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
	int n,k;
	cin>>n>>k;
	vector<int> each;
	int factor = 0;
	while(true){
		int lo = 1;
		int hi = n;
		int ans = -1;
		while(hi>=lo){
			int mid = lo + (hi-lo)/2;
			int num = (2*mid - 1);
			if(num*(1ll<<factor)<=n){
				ans = max(ans,mid);
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if(ans==-1) {
			break;
		}
		each.push_back(ans);
		factor++;
	}
	// peek(each)
	int net = 0;
	int myf = -1;
	for(int i = 0; i<each.size(); i++){
		net += each[i];
		if(net>=k){
			myf = i;
			break;
		}
	}
	int idx = k-(net-each[myf]);
	// cout<<idx<<"\n";
	// cout<<"\n"<<idx;
	cout<<(2*idx - 1)*(1ll<<myf)<<"\n";
}
	return 0;
}