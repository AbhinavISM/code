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
	int k,q;
	cin>>k>>q;
	vector<int> del(k,0);
	for(int i = 0; i<k; i++){
		cin>>del[i];
	}
	while(q--){
		int n;
		cin>>n;
		for(int i = k-1; i>=0; i--){
			if(del[i]<=n){
				n -= i+1;
				i++;
			}
		}
		cout<<n<<" ";
	}
	cout<<"\n";
}
	return 0;
}