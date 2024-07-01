#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int a[4] = {1,0,-1,0};
int b[4] = {0,1,0,-1};
void dfs(vector<vector<char>> &map, int i, int j, vector<vector<bool>> &vis, int &n, int &m){
	vis[i][j] = true;
	for(int k = 0; k<4; k++){
		int ti = i+a[k];
		int tj = j+b[k];
		if(in_range(ti,tj,n,m)&&map[ti][tj]=='.'&&!vis[ti][tj]) dfs(map,ti,tj,vis,n,m);
	}
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<char>> map(n, vector<char>(m));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>map[i][j];
		}	
	}
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	int ans = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(map[i][j]=='.'&&!vis[i][j]){
				ans++;
				dfs(map,i,j,vis,n,m);
			}		
		}	
	}
	cout<<ans;
}