#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	int net = 1;
	map<int,pair<int,int>> m;
	vector<vector<int>> pyramid(2023,vector<int>());
	for(int i = 0; i<2023; i++){
		for(int j = 0; j<=i; j++){
			pyramid[i].push_back(net);
			m[net] = {i,j};
			net++;
		}
	}
	vector<vector<int>> sum(2023,vector<int>());
	net = 1;
	for(int i = 0; i<2023; i++){
		int cum = net*net;
		for(int j = 0; j<=i; j++){
			sum[i].push_back(cum);
			net++;
			cum+=net*net;
		}
	}
	// dpeek(sum)
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	auto p = m[n];
	int row = p.first;
	int col = p.second;
	int locol = p.second;
	int hicol = p.second;
	int ans = 0ll;
	for(int i = row; i>=0; i--){
		if(hicol>i) {hicol = i;}
		if(locol>0) {ans += sum[i][hicol] - sum[i][locol-1];}
		else {ans += sum[i][hicol];}
		locol--;
	}
	cout<<ans<<"\n";
}
	return 0;
}