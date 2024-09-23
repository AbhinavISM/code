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
	int x,y;
	cin>>x>>y;
	int ans = 1;
	for(int i = 0; i<32; i++){
		if((x&(1ll<<i))==(y&(1ll<<i))){
			ans = (1ll<<(i+1));
		} else {
			break;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}