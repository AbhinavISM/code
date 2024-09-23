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
	string s;
	cin>>s;
	int ans = 4;
	// if(s[0]=='0'){ans += 9;}
	// else {ans += (int)(s[0]-'1');}
	for(int i = 0; i<4; i++){
		if(s[i]=='0'){s[i] = ':';}
	}
	ans += (int)(s[0]-'1');
	for(int i = 1; i<4; i++){
		ans += abs((int)(s[i] - s[i-1]));
	}
	cout<<ans<<"\n";
}
	return 0;
}