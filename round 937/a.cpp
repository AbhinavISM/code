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
	int a,b,c;
	cin>>a>>b>>c;
	if(a<b&&b<c){
		cout<<"STAIR\n";
	} else if(a<b&&b>c){
		cout<<"PEAK\n";
	} else {
		cout<<"NONE\n";
	}
}
	return 0;
}