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
	int lastodd = -1;
	int lasteven = -1;
	bool ans = true;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item%2){
			if(item<lastodd) {ans = false;}
			else {lastodd = item;}
		} else {
			if(item<lasteven) {ans = false;}
			else {lasteven = item;}
		}
	}
	if(ans)cout<<"YES\n";
	else cout<<"NO\n";
	
}
	return 0;
}