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
	int n,x,p;
	cin>>n>>x>>p;
	bool flag = false;
	for(int i = 1; i<=2*n&&i<=p; i++){
		if(((((i*(i+1))/2) + x)%n)==0){
			flag = true;
			break;
		}
	}
	if(flag){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}