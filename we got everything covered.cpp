#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	string ans = "";
	for(int i = 0; i<k; i++){
		ans += (char) 97+i;
	}
	for(int i = 0; i<n; i++){
		peek(ans)
		// ans += ans;
	}
	cout<<"\n";
}
	return 0;
}