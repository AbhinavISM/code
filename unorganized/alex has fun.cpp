#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	int n,k;
	cin>>n>>k;
	vector<int> a(n,0);
	int maxi = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		maxi = max(maxi, a[i]);
	}
	int lo = 0;
	int hi = maxi;
	int b = INT_MAX;
	int ctk;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int tk = 0;
		for(int i = 0; i<n; i++){
			if(mid<=a[i]) tk += (a[i]-mid);
		}
		if(tk<=k){
			b = min(b, mid);
			ctk = tk;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(b>=a[i]) continue;
		ans += ((a[i])*(a[i]+1))/2;
		ans -= ((b)*(b+1))/2;	
	}
	k -= ctk;
	ans += (k*b);
	cout<<ans;
}