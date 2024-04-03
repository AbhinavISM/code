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
	int n,l,r;
	cin>>n>>l>>r;
	int ans = 0;
	int fans = 0;
	int ftans = 0;
	for(int i = 0; i<n; i++){
		int a;
		cin>>a;
		if(a>=l&&a<=r){
			ans++;
			fans = max(fans, ans);
		} else {
			ans--;
			ftans = min(ftans, ans);
		}
	}
	cout<<fans<<" "<<ftans<<"\n";
}
	return 0;
}