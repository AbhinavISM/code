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
	string s;
	cin>>s;
	int n = s.size();
	vector<int> possible;
	for(int i = 0; i<=n; i++){
		if(i%2==0){
			possible.push_back(i);
		}
	}
	// peek(possible)
	int lo = 0;
	int hi = possible.size()-1;
	int ans = 0;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int k = possible[mid];
		int found = false;
		for(int i = 0; i<n; i++){
			bool good = true;
			int heh = i;
			int meh = i+k/2;
			if(meh>i+k-1||meh>=n){
				good = false;
			}
			while(meh<=i+k-1&&meh<n){
				if(s[heh]==s[meh]||s[heh]=='?'||s[meh]=='?'){
					heh++;
					meh++;
				} else {
					good = false;
					break;
				}
			}
			if(good){
				found = true;
				break;
			}
		}
		if(found){
		// cout<<mid<<" ";
			ans = max(ans,k);
			lo = mid + 1;
		} else {
		// cout<<mid<<" ";
			// cout<<k<<" ";
			
			hi = mid - 1;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}