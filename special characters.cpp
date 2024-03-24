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
	string ans = "";
	char a = 'A';
	if(n%2){
		cout<<"NO\n";
		continue;
	}
	for(int i = 0; i<n; i+=2){
		ans += a;
		ans += a;
		a = ((char)((int)a+1));
	}
	cout<<"YES\n";
	cout<<ans<<"\n";
}
	return 0;
}