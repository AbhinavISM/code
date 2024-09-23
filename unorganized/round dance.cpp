#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
bool dfs(vector<set<int>> &adj, vector<bool> &vis, int node, int parent){
	vis[node] = true;
	for(int child : adj[node]){
		if((!vis[child]) && child!=parent){
			if(dfs(adj,vis,child,node)){
				return true;
			}
		} else if(child!=parent){
			return true;
		}
	}
	return false;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<set<int>> adj(n,set<int>());
	for(int i = 0; i<n; i++){
		int child;
		cin>>child;
		child--;
		adj[i].insert(child);
		adj[child].insert(i);
	}
	vector<bool> vis(n,false);
	int components = 0;
	int cycles = 0;
	for(int i = 0; i<n; i++){
		if(!vis[i]){
			components++;
			if(dfs(adj,vis,i,i)){
				cycles++;
			}
		}
	}
	if(cycles<components) cout<<cycles+1<<" "<<components<<"\n";
	else cout<<cycles<<" "<<components<<"\n";
	}
}
