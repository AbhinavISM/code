#include<bits/stdc++.h>
#define int long long
using namespace std;
void dfs(vector<vector<int>> &adj, int node, vector<int> &topo, vector<bool> &vis){
	vis[node] = true;
	for(int child : adj[node]){
		if(!vis[child]){
			dfs(adj,child,topo,vis);
		}
	}
	topo.push_back(node);
}
int32_t main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i = 0; i<m; i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	vector<bool> vis(n+1,false);
	vector<int> topo;
	dfs(adj,1,topo,vis);
	reverse(topo.begin(), topo.end());
	// peek(topo)
	vector<int> parent(n+1,-1);
	vector<int> distance(n+1,0);
	distance[1] = 1;
	for(int i = 0; i<topo.size(); i++){
		int node = topo[i];
		for(int child : adj[node]){
			if(distance[child]<distance[node]+1){
				parent[child]=node;
				distance[child] = distance[node]+1;
			}
		}
	}
	if(distance[n]==0)cout<<"IMPOSSIBLE\n";
	else {cout<<(distance[n])<<"\n";
		stack<int> path;
		path.push(n);
		while(path.top()!=-1){
			path.push(parent[path.top()]);
		}
		path.pop();
		while(!path.empty()){
			cout<<path.top()<<" ";
			path.pop();
		}	
	}
	return 0;
}