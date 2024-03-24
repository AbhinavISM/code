#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
	for(int i = 0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u-1].push_back({v-1,w});
	}
	vector<vector<int>> cost(n, vector<int>(2,INT64_MAX));
	vector<vector<bool>> vis(n, vector<bool>(2,false));
	cost[0][0] = 0;
	cost[0][1] = 0;
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{0,0}});
	while(!pq.empty()){
		auto node = pq.top();
		pq.pop();
		int nodeCost = node.first;
		int nodeNum = node.second.first;
		int used = node.second.second;
		if(vis[nodeNum][used]){
			continue;
		}
		vis[nodeNum][used] = true;
		for(auto it : adj[nodeNum]){
			int chlid = it.first;
			int edgeWt = it.second;
			if(used==0){
				if(nodeCost + edgeWt/2 < cost[chlid][1]){
					cost[chlid][1] = nodeCost + edgeWt/2;
					if(!vis[chlid][1]){
						pq.push({cost[chlid][1],{chlid,1}});
					}
				}
			}
			if(nodeCost + edgeWt < cost[chlid][used]){
				cost[chlid][used] = nodeCost + edgeWt;
				if(!vis[chlid][used]){
					pq.push({cost[chlid][used],{chlid,used}});
				}
			}
		}
	}
	cout<<min(cost[n-1][0], cost[n-1][1]);
}