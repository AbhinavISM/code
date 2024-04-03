#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<pii>> graph(n,vector<pii>());
	for(int i = 0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u-1].push_back({v-1,w});
		graph[v-1].push_back({u-1,w});
	}
	vector<int> dis(n,1e12);
	dis[0] = 0;
	set<pair<int,int>> dq;
	dq.insert({0,0});
	vector<int> par(n,-1);
	while(!dq.empty()){
		int node = (*dq.begin()).second;
		dq.erase(dq.begin());
		for(auto e : graph[node]){
			int child = e.first;
			int cost = e.second;
			if(dis[child] > dis[node] + cost){
				dis[child] = dis[node] + cost;
				par[child] = node;
				dq.insert({dis[node] + cost, child});
			}
		}
	}
	if(dis[n-1]==1e12) {cout<<-1<<"\n"; return 0;}
	vector<int> ans;
	int node = n-1;
	ans.push_back(node);
	while(par[node]!=-1){
		node = par[node];
		ans.push_back(node);
	}
	reverse(ans.begin(), ans.end());
	peek(ans)
}