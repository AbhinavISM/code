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
	int n = s.length();
	int onecnt = 0;
	int zerocnt = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='0'){
			zerocnt++;
		} else {
			onecnt++;
		}
	}
	// cout<<onecnt<<" "<<zerocnt<<" ";
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='0'){
			if(onecnt>0) {onecnt--;}
			else {
				ans += (n - i);
				break;
			}
		} else {
			if(zerocnt>0) {zerocnt--;}
			else {
				ans += (n-i);
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}