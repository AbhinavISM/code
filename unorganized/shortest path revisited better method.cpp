#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int32_t main(){
	fast_io;
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
	for(int i = 0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u-1].push_back({v-1,w});
		adj[v-1].push_back({u-1,w});
	}
	vector<vector<int>> cost(n, vector<int>(k+1,INT64_MAX));
	vector<vector<bool>> vis(n, vector<bool>(k+1,false));
	cost[0][0] = 0;
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
			if(used<k){
				if(nodeCost < cost[chlid][used+1]){
					cost[chlid][used+1] = nodeCost;
					if(!vis[chlid][used+1]){
						pq.push({cost[chlid][used+1],{chlid,used+1}});
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
	vector<int> ans;
	for(int i = 0; i<n; i++){
		int mini = INT64_MAX;
		for(int j = 0; j<=k; j++){
			mini = min(mini, cost[i][j]);
		}
		ans.push_back(mini);
	}
	peek(ans)
}