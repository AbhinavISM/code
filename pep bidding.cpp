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
	int atta = 0;
	int defa = 0;
	int attb = 0;
	int defb = 0;
	for(int i = 0; i<n; i++){
		int a; 
		cin>>a;
		atta+=a;
	}
	for(int i = 0; i<n; i++){
		int a; 
		cin>>a;
		defa+=a;
	}
	for(int i = 0; i<n; i++){
		int a; 
		cin>>a;
		attb+=a;
	}
	for(int i = 0; i<n; i++){
		int a; 
		cin>>a;
		defb+=a;
	}
	if(atta>attb&&defa>defb){
		cout<<"A\n";
	} else if(atta<attb&&defa<defb){
		cout<<"P\n";
	} else {
		cout<<"DRAW\n";
	}
}
	return 0;
}