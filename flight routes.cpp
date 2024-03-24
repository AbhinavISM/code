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
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
	for(int i = 0; i<m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u-1].push_back({c,v-1});
	}
	multiset<int> s;
	for(int i = 0; i<k; i++){
		s.insert(INT_MAX);
	}
	vector<multiset<int>> cost(n,s);
	cost[0].erase(cost[0].begin());
	cost[0].insert(0);
	vector<bool> vis(n,0);
	priority_queue<pair<multiset<int>,int>, vector<pair<multiset<int>,int>>, greater<pair<multiset<int>,int>>> pq;
	pq.push({cost[0],0});
	while(!pq.empty()){
		int node = pq.top().second;
		pq.pop();
		if(vis[node]){
			continue;
		}
		vis[node] = true;
		for(auto it : adj[node]){
			int edgeCost = it.first;
			int child = it.second;
			for(int c : cost[node]){
				if(c + edgeCost < *(cost[child].rbegin())){
					cost[child].erase(--(cost[child].end()));
					cost[child].insert(c + edgeCost);
					if(!vis[child]){
						pq.push({cost[child], child});
					}
				}
			}
		}
	}
	for(int ans : cost[n-1]){
		cout<<ans<<" ";
	}
}