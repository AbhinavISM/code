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
	string s;
	cin>>s;
	string f;
	cin>>f;
	int one1 = 0;
	int one2 = 0;
	int displaced1 = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='1'){
			one1++;
		}
		if(f[i]=='1'){
			one2++;
		}
		if(s[i]!=f[i]){
			displaced1++;
		}
	}
	int ans = abs(one1-one2);
	if(displaced1-ans>=0){
	ans += (displaced1-ans)/2;		
	}
	cout<<ans<<"\n";
}
	return 0;
}