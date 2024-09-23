#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool ans = false;
	for(int i = 0; i<n-1; i++){
		if((s[i]=='a'&&s[i+1]=='b')||(s[i]=='b'&&s[i+1]=='a')) {
			ans = true;
		}
	}
	if(ans){
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	return 0;
}