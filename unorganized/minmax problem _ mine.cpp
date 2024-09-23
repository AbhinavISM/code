#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n, m;
	cin>>n>>m;
	vector<vector<int>> a(n, vector<int> (m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	int lo = 0;
	int hi = 1e9;
	while(hi>=lo){
		int mid = lo = (hi-lo)/2;
		vector<int> tmp(n,0);
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				
			}
		}
	}

	return 0;
}