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
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 0; i<=31&&(1<<i)<=x; i++){
		// if(x&(1<<i)){
			int xorr = 0ll;
			int seg = 0ll;
			for(int j = 0; j<n; j++){
				xorr = xorr^a[j];
				if((xorr&(1ll<<i))==0ll){
					int hulu = 0;
					for(int k = 31; k>i; k--){
						if(xorr&(1ll<<k)) hulu += (1ll<<k);
					}
					int bulu = 0;
					for(int k = 31; k>i; k--){
						if(x&(1ll<<k)) bulu += (1ll<<k);
					}
					bool good = true;
					for(int k = i; k<=31; k++){
						bool xorrset = (xorr&(1ll<<k));
						bool xset = (x&(1ll<<k));
						if(xorrset==1&&xset==0){
							good = false;
							break;
						}
					}
					if(hulu==bulu&&good){
						xorr=0ll;
						seg++;
					}
				}
			}
			if(xorr==0ll) ans = max(ans,seg);
		// }
	}
	int seg = 0ll;
	int xorr = 0ll;
	for(int j = 0; j<n; j++){
		xorr = xorr^a[j];
		bool good = true;
		// cout<<xorr<<" ";
		for(int i = 0; i<=31; i++){
			bool xorrset = (xorr&(1ll<<i));
			bool xset = (x&(1ll<<i));
			if(xorrset==1&&xset==0){
				good = false;
				break;
			}
		}
		if(good){
			seg++;
			xorr = 0ll;
		}
	}
	if(xorr==0ll) ans = max(ans,seg);
	if(ans!=0){
		cout<<ans<<"\n";
	} else {
		cout<<-1<<"\n";
	}
}
	return 0;
}