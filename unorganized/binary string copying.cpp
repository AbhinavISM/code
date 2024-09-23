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
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	set<pair<int,int>> intervals;
	for(int i = 0; i<m; i++){
		int l,r;
		cin>>l>>r;
		intervals.insert({l-1,r-1});
	}
	vector<int> nextone(n,-1);
	vector<int> lastzero(n,-1);
	int lzero = -1;
	for(int i = 0; i<n; i++){
		if(s[i]=='0') lzero = i;
		lastzero[i] = lzero;
	}
	int none = INT_MAX;
	for(int i = n-1; i>=0; i--){
		if(s[i]=='1') none = i;
		nextone[i] = none;
	}
	set<pair<int,int>> ans;
	int original = 0;
	for(auto p : intervals){
		int l = p.first;
		int r = p.second;
		if(nextone[l]>r||lastzero[r]<l||nextone[l]>lastzero[r]){
			original = 1;
		} else {
			ans.insert({nextone[l], lastzero[r]});
		}
	}
	cout<<ans.size()+original<<"\n";
}
	return 0;
}