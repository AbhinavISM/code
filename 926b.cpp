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
	int n,k;
	cin>>n>>k;
	if(k<=4*n-4){
		if(k%2==0){
			cout<<k/2<<"\n";
			continue;
		} else {
			cout<<(k/2) + 1<<"\n";
			continue;
		}
	} else if(k==4*n-3){
		cout<<2*n-1<<"\n";
			continue;
	} else {
		cout<<2*n<<"\n";
			continue;
		
	}
}
	return 0;
}