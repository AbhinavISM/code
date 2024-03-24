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
	int mini = INT64_MIN;
	int maxi = INT64_MAX;
	vector<int> forbidden;
	for(int i = 0; i<n; i++){
		int a,x;
		cin>>a>>x;
		if(a==1){
			mini = max(mini,x);
		} else if(a==2){
			maxi = min(maxi,x);
		} else {
			forbidden.push_back(x);
		}
	}
	int notallowed = 0;
	for(int i : forbidden){
		if(i>=mini&&i<=maxi){
			notallowed++;
		}
	}
	if(maxi-mini-notallowed+1>=0) cout<<maxi-mini-notallowed+1<<"\n";
	else cout<<0<<"\n";
}
	return 0;
}