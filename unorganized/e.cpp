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
	int ans = n;
	for(int i = 1; i*i<=n; i++){
		if(n%i==0){

			int d = i;
			set<string> var;
			for(int i = 0; i<n; i+=d){
				var.insert(s.substr(i,d));
			}
			if(var.size()==1){
				ans = min(ans,d);
			} else if(var.size()==2){
				int diff = 0;
				string s1 = *var.begin();
				for(int i = 0; i<n; i++){
					if(s1[i%d]!=s[i]) diff++;
				}
				if(diff==1){
					ans = min(ans,d);
				}
				diff = 0;
				string s2 = *(++var.begin());
				for(int i = 0; i<n; i++){
					if(s2[i%d]!=s[i]) diff++;
				}
				if(diff==1){
					ans = min(ans,d);
				}
			}

			d = n/d;
			var = set<string>();
			for(int i = 0; i<n; i+=d){
				var.insert(s.substr(i,d));
			}
			if(var.size()==1){
				ans = min(ans,d);
			} else if(var.size()==2){
				int diff = 0;
				string s1 = *var.begin();
				for(int i = 0; i<n; i++){
					if(s1[i%d]!=s[i]) diff++;
				}
				if(diff==1){
					ans = min(ans,d);
				}
				diff = 0;
				string s2 = *(++var.begin());
				for(int i = 0; i<n; i++){
					if(s2[i%d]!=s[i]) diff++;
				}
				if(diff==1){
					ans = min(ans,d);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}