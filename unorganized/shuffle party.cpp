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
	int n;
	cin>>n;
	if(n==1){
		cout<<1<<"\n";
	} else {
		int ans = 0;
		while(n>=(1<<ans)){
			ans++;
		}
		cout<<(1<<(ans-1))<<"\n";
	}
}
	return 0;
}