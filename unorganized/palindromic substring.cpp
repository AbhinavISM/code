#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int one = 0;
	int zro = 0;
	string s;
	cin>>s;
	if(n==1) {
		cout<<"Bob\n";
		continue;
	}
	for(int i = 0; i<n; i++){
		int a = s[i] - 48;
		if(a%2) one++;
		else zro++;
	}
	// cout<<one<<" "<<zro<<"\n";
	if(n%2){
		if(abs(one-zro)==1) cout<<"Alice\n";
		else cout<<"Bob\n";
	} else {
		if(one!=zro) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}
	return 0;
}