#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
vector<int> fib(46,0);
bool solve(int n, int r, int c){
	if(n==1){
		return true;
	}
	if(c-fib[n]>0){
		return solve(n-1,fib[n-1] - (c - fib[n]) + 1,r);	
	} else if(fib[n+1]-c>=fib[n]){
		return solve(n-1,fib[n-1] - c + 1,r);
	} else {
		return false;
	}
}
int32_t main(){
	fast_io;
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i<46; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	int t;
	cin>>t;
	while(t--){
	int n,r,c;
	cin>>n>>r>>c;
	cout<<(solve(n,r,c)?"YES\n":"NO\n");
}
	return 0;
}