#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void toposort(vector<bool> &vis, stack<int> &topo, vector<vector<int>> &adj, int node){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            toposort(vis,topo,adj,child);
        }
    }
    topo.push(node);
}
void dfs(vector<bool> &vis, vector<int> &component, vector<vector<int>> &adj, int node){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(vis,component,adj,child);
        }
    }
    component.push_back(node);
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
	stack<int> topo;
	vector<bool> vis(n,false);
	for(int i = 0; i<n; i++){
		if(!vis[i]){
			toposort(vis,topo,adj,i);
		}
	}
	vector<vector<int>> newadj(n,vector<int>());
	for(int i = 0; i<n; i++){
		for(int child : adj[i]){
			newadj[child].push_back(i);
		}
	}
	newadj;
	vis = vector<bool>(n,false);
	vector<vector<int>> scc;
	vector<int> component;
	while(!topo.empty()){
		int i = topo.top();
		topo.pop();
		if(!vis[i]){
			dfs(vis,component,newadj,i);
		}
		if(component.size()>0)scc.push_back(component);
		component = vector<int>();
	}

	vector<int> sccarr(n);
	int scccnt = 0;
	for(auto it : scc){
		for(auto node : it){
			sccarr[node] = scccnt;
		}
		scccnt++;
	}
	// cout<<scccnt<<"\n";
	// peek(sccarr)
	vector<vector<int>> dag(scccnt, vector<int>());
	for(int i = 0; i<n; i++){
		for(int child : adj[i]){
			dag[sccarr[i]].push_back(sccarr[child]);
		}
	}
	stack<int> dag_topo;
	vector<bool> dag_vis(scccnt, false);
	for(int i = 0; i<scccnt; i++){
		if(!dag_vis[i]){
			toposort(dag_vis,dag_topo,dag,i);
		}
	}
	vector<int> rev_dag_topo;
	while(!dag_topo.empty()){
		rev_dag_topo.push_back(dag_topo.top());
		dag_topo.pop();
	}
	reverse(rev_dag_topo.begin(), rev_dag_topo.end());
	int sink_scc = rev_dag_topo[0];
	set<int> ans;
	for(int i = 0; i<n; i++){
		if(sink_scc==sccarr[i]){
			ans.insert(i+1);
		}
	}
	cout<<ans.size()<<"\n";
	peek(ans)
	return 0;
}