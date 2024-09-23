#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	string col = "abcdefgh";
	string row = "12345678";
	for(char c : col){
		if(s[0]!=c){
			cout<<c<<s[1]<<"\n";
		}
	}
	for(char r : row){
		if(s[1]!=r){
			cout<<s[0]<<r<<"\n";
		}
	}
}
	return 0;
}