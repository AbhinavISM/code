#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set
int a[4] = {0, 0, 1, -1};
int b[4] = {1, -1, 0, 0};

bool findCycle(int i, int j, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &cyclic, vector<string> &grid){
	if(cyclic[i][j]!=0) return cyclic[i][j];
	vis[i][j] = 1;

	if(grid[i][j]=='R'){
		if(in_range(i, j+1, n, m)){
			if(vis[i][j+1]==0){
				if(findCycle(i, j+1, n, m, vis, cyclic, grid)){
					cyclic[i][j] = 1;
					return true;
				}
			} else if(vis[i][j+1]==1){
				cyclic[i][j] = 1;
				return true;
			}
		}
	}

	if(grid[i][j]=='L'){
		if(in_range(i, j-1, n, m)){
			if(vis[i][j-1]==0){
				if(findCycle(i, j-1, n, m, vis, cyclic, grid)){
					cyclic[i][j] = 1;
					return true;
				}
			} else if(vis[i][j-1]==1){
				cyclic[i][j] = 1;
				return true;
			}
		}
	}

	if(grid[i][j]=='U'){
		if(in_range(i-1, j, n, m)){
			if(vis[i-1][j]==0){
				if(findCycle(i-1, j, n, m, vis, cyclic, grid)){
					cyclic[i][j] = 1;
					return true;
				}
			} else if(vis[i-1][j]==1){
				cyclic[i][j] = 1;
				return true;
			}
		}
	}

	if(grid[i][j]=='D'){
		if(in_range(i+1, j, n, m)){
			if(vis[i+1][j]==0){
				if(findCycle(i+1, j, n, m, vis, cyclic, grid)){
					cyclic[i][j] = 1;
					return true;
				}
			} else if(vis[i+1][j]==1){
				cyclic[i][j] = 1;
				return true;
			}
		}
	}

	if(grid[i][j]=='?'){
		for(int x = 0; x<4; x++){
			int ni = i + a[x];
			int nj = j + b[x];
			if(in_range(ni, nj, n, m)){
				if(vis[ni][nj]==0){
					if(findCycle(ni, nj, n, m, vis, cyclic, grid)){
						cyclic[i][j] = 1;
						return true;
					}
				} else if(vis[ni][nj]==1){
					cyclic[i][j] = 1;
					return true;
				}
			}
		}
	}
	vis[i][j] = 2;
	return false;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<string> grid(n);
		for(int i = 0; i<n; i++){
			cin>>grid[i];	
		}

		vector<vector<int>> cyclic(n, vector<int>(m, 0));
		vector<vector<int>> vis(n, vector<int>(m, 0));
		for(int row = 0; row<n; row++){
			for(int col = 0; col<m; col++){
				if(vis[row][col]==0){
					findCycle(row, col, n, m, vis, cyclic, grid);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(cyclic[i][j]==1) ans++;
			}	
		}
		cout<<ans<<"\n";
	}
	return 0;
}