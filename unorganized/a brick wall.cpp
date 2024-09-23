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
	int n,m;
	cin>>n>>m;
	if(m%2==0){
		cout<<(n*m)/2<<"\n";
	} else {
		cout<<((n*(m-3))/2 + n)<<"\n";
	}
}
	return 0;
}