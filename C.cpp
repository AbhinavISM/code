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
	int n,k;
	cin>>n>>k;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int i = 0;
	int j = n-1;
	bool ifirst = true;
	int ans = 0;
	while(k>0&&i!=j){
		if(ifirst){
			if(a[i]<=a[j]){
				if(k>= a[i] + a[i] - 1){
					k -= (a[i] + a[i] - 1);
					a[j] -= (a[i] - 1);
					a[i] = 0;
					ans++;
					i++;
					ifirst = false;
				} else {
					k = 0;
				}
			} else {
				if(k>=2*a[j]){
					k -= 2*a[j];
					a[i] -= a[j];
					a[j] = 0;
					ans++;
					j--;
					ifirst = true;
				} else {
					k = 0;
				}
			}
		} else {
			if(a[j]<=a[i]){
				if(k>= a[j] + a[j] - 1){
					k -= (a[j] + a[j] - 1);
					a[i] -= (a[j] - 1);
					a[j] = 0;
					ans++;
					j--;
					ifirst = true;
				} else {
					k = 0;
				}
			} else {
				if(k>=2*a[i]){
					k -= 2*a[i];
					a[j] -= a[i];
					a[i] = 0;
					ans++;
					i++;
					ifirst = false;
				} else {
					k = 0;
				}
			}
		}
	}
	if(i==j&&k>0){
		if(k>=a[i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}