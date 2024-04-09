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
	string tmp;
	cin>>tmp;
	int ans = 1;
	for(int sz = n; sz>=1; sz--){
		set<int> sub;
		string s = tmp;
		int inv = 0;
		for(int i = 0; i+sz-1<n; i++){
			// if(sz==3){cout<<s<<" "<<inv<<" ";}
			if(sub.find(i)!=sub.end()) {sub.erase(i);inv--;}
			if((s[i]=='0'&&inv%2==0)||(s[i]=='1'&&inv%2==1)) {
				inv++;
				s[i]='1';
				sub.insert(i+sz);
			}
		}
		// if(sz==3){cout<<s<<" "<<inv<<" ";}
		bool good = true;
		// if(sz==3) cout<<n-sz+1<<" ";
		for(int i = n-sz+1; i<n; i++){
			if(sub.find(i)!=sub.end()) {sub.erase(i);inv--;}
			if((s[i]=='0'&&inv%2==0)||(s[i]=='1'&&inv%2==1)){
				good = false;
			}
		}
		if(good) {ans = sz; break;}
	}
	cout<<ans<<"\n";
}
	return 0;
}