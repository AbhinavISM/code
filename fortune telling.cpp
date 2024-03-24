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
	int x;
	cin>>x;
	int y;
	cin>>y;
	bool xparity = x%2;
	bool xplus3parity = !xparity;
	bool yparity = y%2;
	bool invert = false;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item%2){
			invert = !invert;
		}
	}
	if(invert){
		xparity = !xparity;
		xplus3parity  = !xplus3parity;
	}
	if(yparity==xparity){
		cout<<"Alice\n";
	} else {
		cout<<"Bob\n";
	}
}
	return 0;
}