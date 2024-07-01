#include<bits/stdc++.h>
#define int long long
#define ld long double
#define itn long long
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
		int u,v,c;
		cin>>u>>v>>c;
		adj[u-1].push_back({c,v-1});
	}
	vector<bool> vis(n,0);
	vector<int> cost(n,INT64_MAX);
	cost[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		int nodeCost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if(vis[node]) continue;
		vis[node] = true;
		for(auto it : adj[node]){
			int child = it.second;
			int edgeWt = it.first;
			if(!vis[child]&&cost[child]>nodeCost + edgeWt){
				cost[child] = nodeCost + edgeWt;
				pq.push({cost[child],child});
			}
		}
	}
	peek(cost)
}