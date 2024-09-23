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
	char last = s[0];
	int i = 1;
	string ans = "";
	ans+=s[0];
	if(s.length()>=2&&s[0]==s[1]){ans = s[0];}
	else{
		while(i<s.length()&&s[i]<=last){
		ans+=s[i];
		last = s[i];
		i++;
	}}
	cout<<ans;
	reverse(ans.begin(), ans.end());
	cout<<ans<<"\n";
}
	return 0;
}