#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
bool basecase(vector<int> &a, int n, int x){
	int hi = n+1;
	int lo = 1;
	while(hi-lo>1){
		int m = (lo + hi)/2;
		if(a[m]<=x){
			lo = m;
		} else {
			hi = m;
		}
	}
	if(a[lo]==x){
		return true;
	} else {
		return false;
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,x;
	cin>>n>>x;
	vector<int> a(n+1);
	int xpos;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		if(a[i]==x){
			xpos = i;
		}
	}

	if(basecase(a,n,x)){
		cout<<0<<"\n";
		continue;
	}
	
	int tmp = a[1];
	a[1] = a[xpos];
	a[xpos] = tmp;
	// peek(a)
	int hi = n+1;
	int lo = 1;
	while(hi-lo>1){
		int m = (lo + hi)/2;
		if(a[m]<=x){
			lo = m;
		} else {
			hi = m;
		}
	}
	if(a[lo]==x){
		cout<<1<<"\n";
		cout<<1<<" "<<xpos<<"\n";
	} else {
		cout<<2<<"\n";
		cout<<1<<" "<<xpos<<"\n";
		cout<<1<<" "<<lo<<"\n";
	}
}
	return 0;
}