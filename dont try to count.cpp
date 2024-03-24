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
	int m;
	cin>>m;
	string x;
	string s;
	cin>>x;
	cin>>s;
	int round = 0;
	bool isFound = false;
	if(x.length()>=s.length()){
		while(round<=3){
		isFound = x.find(s) != string::npos;
		if(isFound){
			break;
		}
		round++;
		x += x;
		}
	}
	else {
		while(x.length()<=4*s.length()){
		isFound = x.find(s) != string::npos;
		if(isFound){
			break;
		}
		round++;
		x += x;
	}
	}
	if(isFound){
		cout<<round<<"\n";
	} else {
		cout<<-1<<"\n";
	}
}
	return 0;
}