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
	int n,q;
	cin>>n>>q;
	for(int i = 1; i<n; i++){
		cout<<i<<" "<<i+1<<"\n";
	}
	int prev = n-1;
	while(q--){
		int d;
		cin>>d;
		if(prev==d){
			cout<<-1<<" "<<-1<<" "<<-1<<"\n";
			continue;
		}
		cout<<n<<" "<<prev<<" "<<d<<"\n";
		prev = d;
	}
}
	return 0;
}