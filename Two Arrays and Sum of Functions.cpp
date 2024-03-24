#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int mod = 998244353;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		cin>>b[i];
	}
	vector<int> newa(n,0);
	newa[0] = n;
	if(n%2){
		for(int i = 1; i<=n/2; i++){
			newa[i] += newa[i-1] + (n-2*i);
		}
		for(int j = n-1; j>n/2; j--){
			newa[j] = newa[n-j-1];
		}
	} else {
		for(int i = 1; i<=(n-1)/2; i++){
			newa[i] += newa[i-1] + (n-2*i);
		}
		for(int j = n-1; j>=n/2; j--){
			newa[j] = newa[n-j-1];
		}
	}
	for(int i = 0; i<n; i++){
		newa[i] *= a[i];
	}
	a = newa;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int ans = 0;
	for(int i = 0; i<n; i++){
		a[i]%=mod;
		ans = (ans + a[i]*b[i])%mod;
	}
	cout<<ans<<"\n";
}