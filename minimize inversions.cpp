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
	map<int,int> m;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	for(int i = 0; i<n; i++){
		cin>>b[i];
	}
	for(int i = 0; i<n; i++){
		m[a[i]] = b[i];
	}
	for(int i = 1; i<=n; i++){
		cout<<i<<" ";
	}
	cout<<"\n";
	for(auto ans : m){
		cout<<ans.second<<" ";
	}
	cout<<"\n";
}
	return 0;
}