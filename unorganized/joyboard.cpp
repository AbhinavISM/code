#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(){
	
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	// solve();
	int n;
	cin>>n;
	int m;
	cin>>m;
	int k;
	cin>>k;
	if(k>3){
		cout<<0<<"\n";
	}
	else if(k==1){
		cout<<1<<"\n";
	}
	else if(k==2){
		if(m<=n){
			cout<<m<<"\n";	
		} else {
			cout<<(n+(m-n)/n)<<"\n";
		}
	}
	else if(k==3){
		if(m<=n){
			cout<<0<<"\n";
		} else {
			cout<<(m-n-((m-n)/n))<<"\n";
		}
	}
}
	return 0;
}