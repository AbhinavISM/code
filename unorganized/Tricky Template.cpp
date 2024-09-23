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
	string a,b,c;
	cin>>a>>b>>c;
	bool ans = false;
	for(int i = 0; i<n; i++){
		if(a[i]==b[i]){
			if(a[i]!=c[i]||b[i]!=c[i]){
				ans = true;
			}
		} else if(a[i]!=b[i]){
			if(a[i]!=c[i]&&b[i]!=c[i]){
				ans = true;
			}
		}
	}
	if(ans){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}