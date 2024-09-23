#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
	for(int i = 0; i<m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u-1].push_back({v-1,c});
		adj[v-1].push_back({u-1,c});
	}
	vector<int> slowness(n);
	for(int i = 0; i<n; i++){
		cin>>slowness[i];
	}
	vector<vector<int>> cost(n, vector<int>(n,INT64_MAX));
	vector<vector<bool>> vis(n, vector<bool>(n,false));
	cost[0][0] = 0;
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{0,0}});
	while(!pq.empty()){
		auto node = pq.top();
		pq.pop();
		int nodeCost = node.first;
		int nodeNum = node.second.first;
		int nodeBike = node.second.second;
		if(vis[nodeNum][nodeBike]){
			continue;
		}
		vis[nodeNum][nodeBike] = true;
		for(auto it : adj[nodeNum]){
			int child = it.first;
			int edgeWt = it.second;
			int childBike = child;
			int bikeToUseLater;
			if(slowness[nodeBike]>=slowness[childBike]){
				bikeToUseLater = childBike;
			} else {
				bikeToUseLater = nodeBike;
			}
			if(nodeCost+slowness[nodeBike]*edgeWt<cost[child][bikeToUseLater]){
				cost[child][bikeToUseLater] = nodeCost+slowness[nodeBike]*edgeWt;
				if(!vis[child][bikeToUseLater]){
					pq.push({cost[child][bikeToUseLater],{child,bikeToUseLater}});
				}
			}
		}
	}
	int ans = INT64_MAX;
	for(int i = 0; i<n; i++){
		ans = min(ans, cost[n-1][i]);
	}
	cout<<ans<<"\n";
}
	return 0;
}	