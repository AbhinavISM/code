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
	vector<int> a(n);
	vector<int> f(n,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		f[item]++;
	}
	if(f[0]==0){
		cout<<0<<"\n";
		continue;
	}
	bool abtak2 = true;
	if(f[0]==1){
		abtak2 = false;
	}
	int ans = 1;
	for(int i = 1; i<n; i++){
		if(f[i]==1&&abtak2){
			abtak2 = false;
		} else if(f[i]<=1){
			break;
		}
		ans = i+1;
	}
	cout<<ans<<"\n";
}
	return 0;
}