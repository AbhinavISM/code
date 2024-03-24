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
	string s;
	cin>>s;
	vector<int> f(26,0);
	for(int i = 0; i<n; i++){
		f[s[i]-65]++;
	}
	int ans = 0;
	for(int i = 0; i<26; i++){
		if(f[i]>=i+1){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}