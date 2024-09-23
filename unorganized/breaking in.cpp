#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j+1<<" ";} cout<<"\n";}
using namespace std;
void toposort(vector<vector<int>> &adj, int node,
	vector<bool> &vis, stack<int> &topo){
	vis[node] = true;
	for(int child : adj[node]){
		if(!vis[child]){
			toposort(adj,child,vis,topo);
		}
	}
	topo.push(node);
}
void dfs(vector<vector<int>> &adj, int node,
	vector<bool> &vis, vector<int> &component){
	vis[node] = true;
	component.push_back(node);
	for(int child : adj[node]){
		if(!vis[child]){
			dfs(adj,child,vis,component);
		}
	}
}
void normaldfs(vector<vector<int>> &adj, int node,
	vector<bool> &vis){
	vis[node] = true;
	for(int child : adj[node]){
		if(!vis[child]){
			normaldfs(adj,child,vis);
		}
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> adj(n,vector<int>());
		for(int i = 0; i<m; i++){
		    int u,v;
		    cin>>u>>v;
		    adj[v-1].push_back(u-1);
		}

		vector<bool> vis(n,false);
		stack<int> topo;
		for(int i = 0; i<n; i++){
			if(!vis[i]){
				toposort(adj,i,vis,topo);
			}
		}

		vector<vector<int>> newadj(n,vector<int>());
	    for(int i = 0; i<n; i++){
	        for(int child : adj[i]){
	            newadj[child].push_back(i);
	        }
	    }

	    vis = vector<bool>(n,false);
	    vector<vector<int>> scc;
	    vector<int> component;
	    while(!topo.empty()){
	        int i = topo.top();
	        topo.pop();
	        if(!vis[i]){
	            dfs(newadj,i,vis,component);
	        }
	        if(component.size()>0)scc.push_back(component);
	        component = vector<int>();
	    }
	    // dpeek(scc)
	    vector<int> sccarr(n);
	    int scccnt = 0;
	    for(auto it : scc){
	        for(auto node : it){
	            sccarr[node] = scccnt;
	        }
	        scccnt++;
	    }
	    // peek(sccarr)
	    vector<vector<int>> dag(scccnt, vector<int>());
	    for(int i = 0; i<n; i++){
	        for(int child : adj[i]){
	            if(sccarr[i]!=sccarr[child]){
	            	dag[sccarr[i]].push_back(sccarr[child]);
	            }
	        }
	    }
	    // dpeek(dag)
	    vector<int> sccimp(scccnt,0);
	    for(int i = 0; i<scccnt; i++){
	    	vector<bool> dagvis(scccnt, false);
		    normaldfs(dag,i,dagvis);
		    for(int j = 0; j<scccnt; j++){
		    	if(dagvis[j]){
		    		sccimp[i] += scc[j].size();
		    	}
		    }
	    }
	    // peek(sccimp)
	    int maximp = 0;
	    for(int i = 0; i<scccnt; i++){
	    	maximp = max(maximp, sccimp[i]);
	    }
	    set<int> ans;
	    for(int i = 0; i<scccnt; i++){
	    	if(sccimp[i]==maximp){
	    		for(int nodeinscc : scc[i]){
	    			ans.insert(nodeinscc);
	    		}
	    	}
	    }
	    peek(ans)
	}
	return 0;
}