#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	vector<string> s(3);
	for(int i = 0; i<3; i++){
		cin>>s[i];
	}
	for(int i = 0; i<3; i++){
		bool founda = false;
		bool foundb = false;
		bool foundc = false;
		bool foundq = false;
		for(int j = 0; j<3; j++){
			if(s[i][j]=='A'){
				founda=true;
			}else if(s[i][j]=='B'){
				foundb=true;
			} else if(s[i][j]=='C'){
				foundc=true;
			} else {
				foundq=true;
			}
		}
		if(foundq){
			if(founda&&foundb){
				cout<<'C'<<'\n';
			} else if(founda&&foundc){
				cout<<'B'<<'\n';
			} else if(foundb&&foundc){
				cout<<'A'<<'\n';
			}
			break;
		}
	}
}
	return 0;
}