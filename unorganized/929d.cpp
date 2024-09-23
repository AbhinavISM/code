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
	map<int,int> a;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[item]++;
	}
	int smallest = (*a.begin()).first;
	int smallcnt = (*a.begin()).second;
	// cout<<t<<" ";
	if(smallcnt>1&&smallest==1){
		cout<<"NO\n";
	} else if(smallcnt>1){
		bool good = false;
		for(auto it : a){
			if(it.first!=smallest){
				if(it.first%smallest!=0){
					good = true;
				}
			}
		}
		if(!good){
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	} else {
		cout<<"YES\n";
	}
}
	return 0;
}