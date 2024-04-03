#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j+1<<" ";} cout<<"\n";}
using namespace std;
void dfs(vector<vector<int>> &adj, vector<int> &par, int node, int p){
	for(int child : adj[node]){
		if(child!=p){
			par[child] = node;
			dfs(adj,par,child,node);
		}
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<n-1; i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u-1].push_back(v-1);
	    adj[v-1].push_back(u-1);
	}
	int k = 0;
	for(int i = 1; i<n; i++){
	    if(adj[i].size()==1){
	    	k++;
	    }
	}
	vector<int> leaves(k);
	for(int i = 0; i<k; i++){
		cin>>leaves[i];
		leaves[i]--;
	}
	leaves.push_back(0);
	vector<int> ans;
	int node = 0;
	ans.push_back(0);
	for(int leaf : leaves){
		vector<int> par(n,-1);
		dfs(adj,par,node,-1);
		node = leaf;
		stack<int> tmp;
		while(par[leaf]!=-1){
			tmp.push(leaf);
			leaf = par[leaf];
		}
		while(!tmp.empty()){
			ans.push_back(tmp.top());
			tmp.pop();
		}
	}
	if (ans.size()>2*(n-1)+1){cout<<-1<<"\n";}
	else {peek(ans)}
}