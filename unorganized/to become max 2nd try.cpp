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
	int k;
	cin>>k;
	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		ans = max(ans, a[i]);
	}
	for(int i = 0; i<n-1; i++){
		int hi = a[i] + k;
		int lo = a[i];
		int aukat_of_ai = 0;
		while(hi>=lo){
			int mid = lo + (hi-lo)/2;
			int tk = k;
			bool good = true;
			for(int j = i; j<n; j++){
				if((mid-(j-i))>a[j]){
					tk-=((mid-(j-i))-a[j]);
					if(tk<0||j==n-1){
						good = false;
						break;
					}
				} else {
					break;
				}
			}
			if(good){
				aukat_of_ai = max(aukat_of_ai,mid);
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		// cout<<aukat_of_ai<<" ";
		ans = max(ans, aukat_of_ai);
	}
	cout<<ans<<"\n";
}
	return 0;
}