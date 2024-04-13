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
	int n;
	cin>>n;
	int onecnt = 0;
	int towcnt = 0;
	for(int i = 0; i<n; i++){
		int a;
		cin>>a;
		if(a==1) onecnt++;
		else towcnt++;
	}
	if(onecnt==n) {cout<<"YES\n"; continue;}
	if(towcnt%8==0){cout<<"YES\n"; continue;}
	cout<<"NO\n";
	// cout<<val<<"\n";
	// bool good = true;
	// while(val>1){
	// 	if(val%256==0){
	// 		val/=256;
	// 	} else {
	// 		good = false;
	// 		break;
	// 	}
	// }
	// if(good){
	// 	cout<<"YES\n";
	// } else {
	// 	cout<<"NO\n";
	// }
}
	return 0;
}