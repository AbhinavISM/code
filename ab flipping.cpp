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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int i = 0;
	while(s[i]=='B'&&i<n) i++;
	bool finda = true;
	int ans = 0;
	int cnt = 0;
	for(; i<n; i++){
		if(finda&&s[i]=='A') {cnt++;}
		else if(finda&&s[i]=='B') {cnt++; finda = false;}
		else if((!finda)&&s[i]=='B') {cnt++;}
		else if((!finda)&&s[i]=='A') {ans += cnt-1; cnt = 1; finda = true;s[i-1]='A';i--;}
		// cout<<cnt<<" ";
	}
	if((!finda)&&s[n-1]=='B') ans += cnt-1;
	cout<<ans<<"\n";
}
	return 0;
}