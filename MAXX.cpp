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
	int x;
	cin>>x;
	vector<int> bitx;
	int tmp = x;
	while(tmp>0){
		bitx.push_back(tmp%2);
		tmp/=2;
	}
	reverse(bitx.begin(), bitx.end());
	vector<int> bita;
	for(int i = 0; i<bitx.size(); i++){
		bita.push_back(bitx[i]);
	}
	for(int i = 0; i<bitx.size(); i++){
		bita.push_back(bitx[i]);
	}
	vector<int> bitb;
	for(int i = 0; i<bitx.size(); i++){
		bitb.push_back(bitx[i]);
	}
	for(int i = 0; i<bitx.size(); i++){
		bitb.push_back(0);
	}
	int a = 0;
	int j = bita.size()-1;
	for(int i = 0; i<bita.size(); i++){
		if(bita[i]==1) a += (1ll<<j);
		j--;
	}
	int b = 0;
	j = bitb.size()-1;
	for(int i = 0; i<bitb.size(); i++){
		if(bitb[i]==1) b += (1ll<<j);
		j--;
	}
	// int a = x;
	// a = (a<<bitx.size());
	// cout<<x+a<<" "<<a<<"\n";
	// peek(bitx)
	// peek(bita)
	// peek(bitb)
	cout<<a<<" "<<b<<"\n";
}
	return 0;
}