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
	string s;
	cin>>s;
	int n = s.size();
	int ans = 0;
	for(int i = 2; i<=n; i+=2){
		int j = 0;
		int k = i-1;
		int bad = 0;
		for(int l = 0; l<i/2; l++){
			if(s[l]!=s[l+(i/2)]&&s[l]!='?'&&s[l+(i/2)]!='?'){
				bad++;
			}
		}
		if(bad==0){
			ans = max(ans,i);
		}
		j++;
		k++;
		while(k<n){
			if(s[j-1]!=s[j-1+i/2]&&s[j-1]!='?'&&s[j-1+(i/2)]!='?'){bad--;}
			if(s[j+(i/2)-1]!=s[k]&&s[j+(i/2)-1]!='?'&&s[k]!='?'){bad++;}
			if(bad==0){
				ans = max(ans,i);
			}
			j++;
			k++;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}