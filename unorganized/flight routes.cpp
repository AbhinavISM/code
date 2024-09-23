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
		s.insert(INT64_MAX);
	}
	vector<multiset<int>> cost(n,s);
	cost[0].erase(cost[0].begin());
	cost[0].insert(0);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({*cost[0].begin(),0});
	while(!pq.empty()){
		int node = pq.top().second;
		int nodeCost = pq.top().first;
		pq.pop();
		//this if condition is only for speed up, its correct even if you remove it.
		if(*(cost[node].rbegin()) < nodeCost) continue;
		for(auto it : adj[node]){
			int edgeCost = it.first;
			int child = it.second;
			if(nodeCost + edgeCost < *(cost[child].rbegin())){
				cost[child].erase(--(cost[child].end()));
				cost[child].insert(nodeCost + edgeCost);
				pq.push({nodeCost + edgeCost, child});
			}
		}
	}
	for(int ans : cost[n-1]){
		cout<<ans<<" ";
	}
}