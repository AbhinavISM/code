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
	int n,x;
	cin>>n>>x;
	vector<int> a(n+1);
	vector<int> f(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		f[i] = f[i-1] + a[i];
	}
	vector<int> submax(n+1,INT_MIN);
	submax[0] = 0;
	for(int j = 1; j<=n; j++){
		for(int i = 1; i<=n; i++){
			if(i-j>=0) submax[j] = max(submax[j], f[i] - f[i-j]);
		}		
	}
	// peek(submax)
	for(int j = 0; j<=n; j++){
		int ans = INT_MIN;
		for(int i = 0; i<=n; i++){
			ans = max(ans, submax[i] + ((i>=j)?j*x:i*x));
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
}
	return 0;
}