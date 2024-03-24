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
	int i = 0;
	int j = s.size()-1;
	bool rev = false;
	while(i<j){
		if(s[i]>s[j]){
			rev = true;
			break;
		} else if(s[i]<s[j]){
			break;
		}
		i++;
		j--;
	}
	if(rev){
		string ans ="";
		string temp = s;
		reverse(s.begin(), s.end());
		ans += s;
		ans += temp;
		cout<<ans<<"\n";
	} else {
		cout<<s<<"\n";
	}
}
	return 0;
}