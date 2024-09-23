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
	int n;
	cin>>n;
	vector<int> a(n+2);
	vector<int> twof(n+2,0);
	vector<int> twor(n+2,0);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		a[i] = item;
		if(item==2){
			twof[i] = twof[i-1] + 1;
		} else {
			twof[i] = twof[i-1];
		}
	}
	for(int i = n; i>=1; i--){
		if(a[i]==2){
			twor[i] = twor[i+1] + 1;
		} else {	
			twor[i] = twor[i+1];
		}
	}
	int ans = -1;
	for(int i = 1; i<=n; i++){
		if(twof[i]==twor[i+1]) {
			ans = i;
			break;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}