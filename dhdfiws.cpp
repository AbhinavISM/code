#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

void solve(vector<vector<int>> floorplan, int battery, int clean, int x, int y, int &ans){
	if(battery>=1&&x==0&&y==0&&floorplan[0][0]==2){
		ans = max(ans, clean);
		return;
	} if(battery==1){
		return;
	}
	floorplan[x][y] = 2;
	int c[] = {0, -1, 0, 1};
    int b[] = {-1, 0, 1, 0};
    int n = floorplan.size();
    int m = floorplan[0].size();
    for(int i=0;i<4;i++){
        int tmpX = x + c[i];
        int tmpY = y + b[i];
        if(in_range(tmpX, tmpY, n, m)){
        	if(floorplan[tmpX][tmpY]==0){
        		solve(floorplan, battery-1, clean + 1, tmpX, tmpY, ans);
        	} else if(floorplan[tmpX][tmpY]==2){
        		solve(floorplan, battery-1, clean, tmpX, tmpY, ans);
        	}
		}
	}
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>a[i][j];
		}
	}
	int battery;
	cin>>battery;
	int ans = 0;
	solve(a, battery, 1, 0, 0, ans);
	cout<<ans;
}