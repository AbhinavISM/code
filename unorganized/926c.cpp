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
	int k,x,a;
	cin>>k>>x>>a;
	int lost = 0;
	for(int r = 1; r<=x+1; r++){
		int bet = (lost)/(k-1) + 1;
		lost += bet;
		if(a<lost) break;
	}
	if(a>=lost){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}