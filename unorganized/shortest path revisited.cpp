#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
struct node
{
	int num;
	int used;
};

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
	vector<vector<vector<pair<node,int>>>> model(n,
	vector<vector<pair<node,int>>>(k+1,
	vector<pair<node,int>>()));

	for(int i = 0; i<n; i++){
		for(int j = 0; j<=k; j++){
			for(auto p : adj[i]){
				node child1 = {
					p.first,
					j,
				};
				model[i][j].push_back({child1, p.second});
				if(j!=k){
					node child2 = {
						p.first,
						j+1,
					};
					model[i][j].push_back({child2, 0});					
				}
			}
		}
	}
	vector<vector<bool>> vis(n,vector<bool>(k+1,0));
	vector<vector<int>> cost(n,vector<int>(k+1,INT64_MAX));
	cost[0][0] = 0;
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{0,0}});
	while(!pq.empty()){
		pair<int,int> p = pq.top().second;
		node nd = {
			p.first,
			p.second,
		};
		pq.pop();
		if(vis[nd.num][nd.used]){
			continue;
		}
		vis[nd.num][nd.used] = true;
		for(auto it : model[nd.num][nd.used]){
			if(cost[nd.num][nd.used] + it.second < cost[it.first.num][it.first.used]){
				cost[it.first.num][it.first.used] = cost[nd.num][nd.used] + it.second;
				if(!vis[it.first.num][it.first.used]){
					pq.push({cost[it.first.num][it.first.used], {it.first.num,it.first.used}});
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