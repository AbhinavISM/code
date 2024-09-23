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
	for(int i = 0; i<n-2; i++){
		if(i+2<n&&s[i]=='m'&&s[i+1]=='a'&&s[i+2]=='p'){
			if(i+4<n&&s[i+3]=='i'&&s[i+4]=='e'){
				s[i+2] = '1';
				i = i+2;
			} else {
				s[i+1] = '1';
				i = i+1;
			}
		}
		if(i+2<n&&s[i]=='p'&&s[i+1]=='i'&&s[i+2]=='e'){
			s[i+1] = '1';
			i = i+1;
		}
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='1'){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}