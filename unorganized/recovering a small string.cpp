#include<bits/stdc++.h>
#define int long long
#define ld long double
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
	if(n<=28){
		cout<<((char)(96 + 1))<<((char)(96 + 1))<<((char)(96 + (n-2)))<<"\n";
	} else if(n<=53){
		cout<<((char)(96 + 1))<<((char)(96 + (n-26-1)))<<((char)(96 + 26))<<"\n";
	} else {
		cout<<((char)(96 + (n-52)))<<((char)(96 + 26))<<((char)(96 + 26))<<"\n";
	}
}
	return 0;
}