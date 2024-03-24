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
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	bitset<10> start;
	pq.push({0, {0,start.to_ullong()}});
	for(int fish : fishSold[0]){
		start.set(fish);
		pq.push({0, {0,start.to_ullong()}});
	}
	while(!pq.empty()){
		auto node = pq.top();
		pq.pop();
		int nodeCost = node.first;
		int nodeNum = node.second.first;
		int nodeFish = node.second.second;
		if(vis[nodeNum][nodeFish]){
			continue;
		}
		vis[nodeNum][nodeFish] = true;
		for(auto it : adj[nodeNum]){
			int child = it.first;
			int edgewt = it.second;
			bitset<10> childFishBit(nodeFish);
			if(nodeCost + edgewt < cost[child][childFishBit.to_ullong()]){
				cost[child][childFishBit.to_ullong()] = nodeCost + edgewt;
				if(!vis[child][childFishBit.to_ullong()]){
					pq.push({cost[child][childFishBit.to_ullong()], {child, childFishBit.to_ullong()}});
				}
			}
			for(int fish : fishSold[child]){
				childFishBit.set(fish);
				if(nodeCost + edgewt < cost[child][childFishBit.to_ullong()]){
					cost[child][childFishBit.to_ullong()] = nodeCost + edgewt;
					if(!vis[child][childFishBit.to_ullong()]){
						pq.push({cost[child][childFishBit.to_ullong()], {child, childFishBit.to_ullong()}});
					}
				}
			}
		}
	}
	int ans = cost[n-1][(1<<k)-1];
	for(int mask = 0; mask < (1 << k); mask++) {
		int other = 0;
		for(int i = 0; i < k; i++) {
			if(mask & (1 << i)) {
			} else {
				other += (1<<i);
			}
		}
		ans = min(ans, max(cost[n-1][mask], cost[n-1][other]));
	}
	cout<<ans;
}