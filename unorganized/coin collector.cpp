#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
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
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n,vector<int>());
	vector<int> coins(n);
	for(int i = 0; i<n; i++){
		cin>>coins[i];
	}
	for(int i = 0; i<m; i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u-1].push_back(v-1);
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
 
    vector<int> sccarr(n);
    int scccnt = 0;
    for(auto it : scc){
        for(auto node : it){
            sccarr[node] = scccnt;
        }
        scccnt++;
    }
 
    vector<vector<int>> dag(scccnt, vector<int>());
    for(int i = 0; i<n; i++){
        for(int child : adj[i]){
            if(sccarr[i]!=sccarr[child]){
            	dag[sccarr[i]].push_back(sccarr[child]);
            }
        }
    }
 
    vector<int> dagcoins(scccnt,0);
    for(int i = 0; i<n; i++){
    	dagcoins[sccarr[i]] += coins[i];
    }
 
    vector<bool> dagvis(scccnt, false);
    stack<int> dagtopo;
    for(int i = 0; i<scccnt; i++){
	    if(!dagvis[i]){
		    toposort(dag,i,dagvis,dagtopo);    		    	
	    }
    }
 
    vector<int> revdagtopo;
    while(!dagtopo.empty()){
    	revdagtopo.push_back(dagtopo.top());
    	dagtopo.pop();
    }
    reverse(revdagtopo.begin(), revdagtopo.end());
 
    vector<int> dp(scccnt,0);
    for(int node : revdagtopo){
    	for(int child : dag[node]){
    		dp[node] = max(dp[node], dp[child]);
    	}
    	dp[node] += dagcoins[node];
    }
    int ans = 0;
    for(int i = 0; i<scccnt; i++){
    	ans = max(ans, dp[i]);
    }
    cout<<ans;
	return 0;
}