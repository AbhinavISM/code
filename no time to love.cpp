#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	int r,c;
	cin>>r>>c;
	vector<vector<int>> a(r,vector<int>(c));
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c-1; j++){
			cin>>a[i][j];	
		}
	}
	vector<vector<int>> b(r,vector<int>(c));
	for(int i = 0; i<r-1; i++){
		for(int j = 0; j<c; j++){
			cin>>b[i][j];	
		}
	}
	vector<vector<bool>> vis(r,vector<bool>(c,false));
	vector<vector<int>> cost(r,vector<int>(c,INT64_MAX));
	cost[0][0] = 0;
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{0,0}});
	while(!pq.empty()){
	    int nr = pq.top().second.first;
	    int nc = pq.top().second.second;
	    int ncost = pq.top().first;
	    pq.pop();
	    if(vis[nr][nc]){
	        continue;
	    }
	    vis[nr][nc] = true;
	    if(nc+1<c&&!vis[nr][nc+1]&&ncost+a[nr][nc]<cost[nr][nc+1]){
	    	cost[nr][nc+1] = ncost + a[nr][nc];
	        pq.push({cost[nr][nc+1], {nr,nc+1}});
	    }
	    if(nc-1>=0&&!vis[nr][nc-1]&&ncost+a[nr][nc-1]<cost[nr][nc-1]){
	    	cost[nr][nc-1] = ncost + a[nr][nc-1];
	        pq.push({cost[nr][nc-1], {nr,nc-1}});
	    }
	    if(nr+1<r&&!vis[nr+1][nc]&&ncost+b[nr][nc]<cost[nr+1][nc]){
	    	cost[nr+1][nc] = ncost + b[nr][nc];
	        pq.push({cost[nr+1][nc], {nr+1,nc}});
	    }
	    for(int i = 1; i<=r; i++){
	    	if(nr-i>=0&&!vis[nr-i][nc]&&ncost+i+1<cost[nr-i][nc]){
	    		cost[nr-i][nc] = ncost+i+1;
	    		pq.push({cost[nr-i][nc], {nr-i,nc}});
	    	}
	    }
	}
	cout<<cost[r-1][c-1];
}