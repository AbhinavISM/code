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
	bool allxp = true;
	bool allxn = true;
	bool allyp = true;
	bool allyn = true;
	for(int i = 0; i<n; i++){
		int x,y;
		cin>>x>>y;
		if(x>0){
			allxn = false;
		} else if(x<0){
			allxp = false;
		}
		if(y>0){
			allyn = false;
		} else if(y<0){
			allyp = false;
		}
	}
	if(allxn||allxp||allyn||allyp){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}