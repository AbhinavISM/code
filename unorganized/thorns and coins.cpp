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
	char last = s[0];
	int coins = 0;
	for(int i = 1; i<n; i++){
		if(s[i]=='*'&&s[i]==last){
			break;
		} else if(s[i]=='.'){
			last = s[i];
		} else if(s[i]=='@'){
			last = s[i];
			coins++;
		} else if(s[i]=='*'){
			last = s[i];
		}
	}
	cout<<coins<<"\n";
}
	return 0;
}