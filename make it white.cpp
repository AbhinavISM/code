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
	int firstB = INT_MAX;
	int lastB = -1;
	for(int i = 0; i<n; i++){
		if(s[i]=='B'){
			firstB = min(firstB, i);
			lastB = max(lastB, i);
		}
	}
	if(firstB==INT_MAX&&lastB==-1){
		cout<<0<<"\n";
	} else {
		cout<<lastB-firstB+1<<"\n";
	}
}
	return 0;
}