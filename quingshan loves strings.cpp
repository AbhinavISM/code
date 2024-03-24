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
	int n;
	cin>>n;
	int m;
	cin>>m;
	string s;
	cin>>s;
	string t;
	cin>>t;
	bool sgood = true;
	bool s1bad = false;
	bool s0bad = false;
	for(int i = 0; i<n-1; i++){
		if(s[i]==s[i+1]){
			if(s[i]=='1'){
				s1bad = true;
			} else {
				s0bad = true;
			}
			sgood = false;
		}
	}
	bool tgood = true;
	for(int i = 0; i<m-1; i++){
		if(t[i]==t[i+1]){
			tgood = false;
		}
	}
	if(sgood){
		cout<<"YES\n";
	} else if(tgood==false){
		cout<<"NO\n";
	} else if(t[0]!=t[m-1]){
		cout<<"NO\n";
	} else {
		if((t[0]=='0'&&s0bad)||(t[0]=='1'&&s1bad)){
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	}
}
	return 0;
}