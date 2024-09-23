#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i = 0; i<n; i++){
		if(s[i]=='0'){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	solve();
}
	return 0;
}