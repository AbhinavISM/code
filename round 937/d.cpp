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
	set<int> a;
	a.insert(0);
	a.insert(1);
	int f = 10;
	while(f<=10000){
		set<int> b;
		for(int e : a){
			b.insert(e+f);
		}
		for(int e : b){
			a.insert(e);
		}
		f*=10;
	}
	a.insert(100000);
	a.erase(0);
	a.erase(1);
	// cout<<a.size()<<" ";
	// peek(a)
	while(t--){
	int n;
	cin>>n;
	if(a.find(n)!=a.end()){
		cout<<"YES\n";
		continue;
	}
	for(int e : a){
		while(n%e==0){
			n/=e;
		}
	}
	if(n==1){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}