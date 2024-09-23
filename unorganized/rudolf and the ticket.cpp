
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
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> b(m);
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		b[i] = item;
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(a[i] + b[j] <=k){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}