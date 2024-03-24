#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
pair<bool,int> dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &parent, int node){
	vis[node] = 1;
	for(int child : adj[node]){
		if(vis[child]==vis[node]){
			parent[child] = node;
			return {true,node};
		}
		if(vis[child]==0){
			parent[child] = node;
			auto tulu = dfs(adj,vis,parent,child);
			if(tulu.first){
				return tulu;
			}
		}
	}
	vis[node] = 2;
	return {false,-1};
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
	}
	vector<int> parent(n,-1);
	vector<int> vis(n,0);
	for(int i = 0; i<n; i++){
		if(vis[i]==0){
			auto tulu = dfs(adj,vis,parent,i);
			if(tulu.first){
				stack<int> path;
				path.push(tulu.second);
				path.push(parent[path.top()]);
				while(path.top()!=tulu.second){
					path.push(parent[path.top()]);
				}
				cout<<path.size()<<"\n";
				while(!path.empty()){
					cout<<path.top()+1<<" ";
					path.pop();
				}
				return 0;
			}
		}		
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}