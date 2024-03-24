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
	int k;
	cin>>k;
	string s;
	string t;
	cin>>s>>t;
	vector<int> sfeq(26,0);
	vector<int> tfeq(26,0);
	for(int i = 0; i<n; i++){
		sfeq[s[i]-'a']++;
	}
	for(int i = 0; i<n; i++){
		tfeq[t[i]-'a']++;
	}
	if(n<=3){
		if(s==t){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		continue;
	}
	if(n==4){
		if((s[0]==t[0]&&s[n-1]==t[n-1])||(s[0]==t[n-1]&&s[n-1]==t[0])){
			bool good = true;
			for(int i = 1; i<n-1; i++){
				if(s[i]!=t[i]){
					good = false;
				}
			}
			if(good){
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		} else {
			cout<<"NO\n";
		}
		continue;
	}
	if(n==5){
		if(s[2]==t[2]){
			bool good = true;
			for(int i = 0; i<26; i++){
				if(sfeq[i]!=tfeq[i]){
					good = false;
				}
			}
			if(good){
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		} else {
			cout<<"NO\n";
		}
		continue;
	}
	if(n>=6){
		bool good = true;
		for(int i = 0; i<26; i++){
			if(sfeq[i]!=tfeq[i]){
				good = false;
			}
		}
		if(good){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		continue;
	}

}
	return 0;
}