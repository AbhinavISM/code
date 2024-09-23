#include<bits/stdc++.h>
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	vector<vector<int>> facs(1000001, vector<int>());
	for(int i = 1; i<1000001; i++) {
        for (int j = i; j < 1000001; j+=i) {
            facs[j].push_back(i);
        }
    }
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	int mat[n+1][m+1];
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>mat[i][j];
		}
	}
	int best = min(mat[1][1], mat[n][m]);
	int ans = -1;
	vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
	for(int i = facs[best].size()-1; i>=0; i--){
		int d = facs[best][i];
		//assign works fast too
		// vis.assign(n+1,vector<bool>(m+1,false));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				vis[i][j] = false;
			}
		}
		vis[1][1] = true;
		for(int j = 1; j<=n; j++){
			for(int k = 1; k<=m; k++){
				if(mat[j][k]%d!=0) {vis[j][k] = false; continue;} 
				if(vis[j-1][k]||vis[j][k-1]) {vis[j][k] = true;continue;}
			}
		}
		if(vis[n][m]) {ans = max(ans,d);break;}
	}
	cout<<ans<<"\n";
}
	return 0;
}