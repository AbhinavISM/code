#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m,k;
	cin>>n>>m>>k;
	if(m==1){
		cout<<"NO\n";
	} else if(n%m){
		if(n-n/m-1<=k) cout<<"NO\n";
		else cout<<"YES\n";
	} else {
		if(n-n/m<=k) cout<<"NO\n";
		else cout<<"YES\n";
	}
}
	return 0;
}