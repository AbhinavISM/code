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
	int l,r,k;
	cin>>l>>r>>k;
	int req;
	if(l==r&&l!=1){
		cout<<"YES\n";
		continue;
	} else if(l==r&&l==1){
		cout<<"NO\n";
		continue;
	}
	if(l%2==0&&r%2==0){
		req = ((r-l)/2);
	} else  if(l%2==1&&r%2==1){
		req = ((r-l)/2 + 1);
	} else {
		req = ((r-l+1)/2);
	}
	if(req<=k){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}