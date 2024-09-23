#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	vector<vector<int>> cntmat(7,vector<int>(7,0));
	int matcnt = 0;
	for(int i = 0; i<7; i++){
		for(int j = 0; j<7; j++){
			cntmat[i][j] = matcnt;
			matcnt++;
		}
	}
	vector<vector<int>> adj(matcnt,vector<int>());
	int cnt = 0;
	for(int i = 0; i<7; i++){
		for(int j = 0; j<7; j++){
			if(i>0&&j>0)adj[cnt].push_back(cntmat[i-1][j-1]);
			if(i>0&&j<6)adj[cnt].push_back(cntmat[i-1][j+1]);
			if(i<6&&j>0)adj[cnt].push_back(cntmat[i+1][j-1]);
			if(i<6&&j<6)adj[cnt].push_back(cntmat[i+1][j+1]);
			cnt++;
		}
	}
	dpeek(adj)
	// int t;
	// cin>>t;
	// while(t--){
	// int n;
	// cin>>n;
	// vector<string> a(7);
	// for(int i = 0; i<7; i++){
	// 	cin>>a[i];
	// }
	
// }
	return 0;
}