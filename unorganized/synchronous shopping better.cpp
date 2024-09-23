#include<bits/stdc++.h>
#define int unsigned long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) if(x!=INT64_MAX)cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> fishSold;
	for(int i = 0; i<n; i++){
		int ti;
		cin>>ti;
		fishSold.push_back(vector<int>(ti));
		for(int j = 0; j<ti; j++){
			cin>>fishSold[i][j];
			fishSold[i][j]--;
		}
	}
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
	for(int i = 0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u-1].push_back({v-1,w});
		adj[v-1].push_back({u-1,w});
	} 
	vector<vector<bool>> vis(n,vector<bool>((1<<k),false));
	vector<vector<int>> cost(n,vector<int>((1<<k),INT64_MAX));
	//{cost,{node,state}}
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
	int fristMask = 0;
	for(int fish : fishSold[0]){
		fristMask |= (1<<fish);
	}
	pq.push({0,{0,fristMask}});
	cost[0][fristMask] = 0;
	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();
		int nodeCost = it.first;
		int node = it.second.first;
		int mask = it.second.second;
		if(vis[node][mask]) continue;
		vis[node][mask] = true;
		for(auto adjIt : adj[node]){
			int child =  adjIt.first;
			int edgeCost = adjIt.second;
			int newMask = mask;
			for(int fish : fishSold[child]){
				newMask |= (1<<fish);
			}
			if(!vis[child][newMask]
				&&cost[child][newMask]>nodeCost+edgeCost){
				cost[child][newMask] = nodeCost+edgeCost;
				pq.push({cost[child][newMask],{child,newMask}});
			}
		}
	}
	// dpeek(cost)
	int ans = cost[n-1][(1<<k)-1];
    for(int mask = 0; mask < (1 << k); mask++) {
    	for(int mask2 = 0; mask2 < (1 << k); mask2++) {
    		if((mask|mask2)==((1<<k)-1)){    			
        		ans = min(ans, max(cost[n-1][mask], cost[n-1][mask2]));
    		}
    	}
    }
	cout<<ans;
}