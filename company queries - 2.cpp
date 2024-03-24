#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

void level_bfs(vector<vector<int>> &adj, vector<int> &dis, int root){
	queue<int> q;
	q.push(root);
	dis[root] = 0;
	while(!q.empty()){
	    int node = q.front();
	    q.pop();
	    for(int child : adj[node]){
	        if(dis[child]==INT_MAX){
	            dis[child] = dis[node] + 1;
	            q.push(child);
	        }
	    }
	}
}

void binlift_dfs(vector<vector<int>> &adj, vector<vector<int>> &binlift,
	int x, int par, int node){
	// we dont need vis array as it is a tree and we have immediate parent(p)
		binlift[node][0] = par;
		for(int i = 1; i<=x; i++){
			if(binlift[node][i-1]!=-1) {
				binlift[node][i] = binlift[binlift[node][i-1]][i-1];
			} else {
				binlift[node][i] = -1;
			}
		}
	for(int child : adj[node]){
		if(child!=par){
			binlift_dfs(adj,binlift,x,node,child);
		}
	}
}

int lift_node(int node, int jmp, int x, vector<vector<int>> &binlift){
	for(int j = 0; j<=x; j++){
		if((1ll<<j)&jmp){
			node = binlift[node][j];
			if(node==-1){break;}
		}
	}
	return node;
}

// O(logn*logn) per query
int LCA1 (int u, int v, int x, vector<vector<int>> &binlift,
	vector<int> &level){

	// bring u and v to the same level
	if(level[u]<level[v]){
		v = lift_node(v,level[v] - level[u],x,binlift);
	} else {
		u = lift_node(u,level[u] - level[v],x,binlift);
	}
	
	if(u==v){
		return u;
	}

	int lo = 0;
	//putting this limit on 'hi' will make sure that we do not get
	// -1 as node when calling lift_node
	int hi = level[u];
	int ans;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		int p1 = lift_node(u,mid,x,binlift);
		int p2 = lift_node(v,mid,x,binlift);
		if(p1==p2){
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lift_node(u,ans,x,binlift);
}
//O(logn) per query
int LCA2 (int u, int v, int x, vector<vector<int>> &binlift,
	vector<int> &level){

	// bring u and v to the same level
	if(level[u]<level[v]){
		v = lift_node(v,level[v] - level[u],x,binlift);
	} else {
		u = lift_node(u,level[u] - level[v],x,binlift);
	}

	if(u==v){
		return u;
	}

	for(int i = x; i>=0; i--){
		if(binlift[u][i] != binlift[v][i]){
			u = binlift[u][i];
			v = binlift[v][i];
		}
	}

	return binlift[u][0];
}
int32_t main(){
	fast_io;
	int n,q;
	cin>>n>>q;
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i = 2; i<=n; i++){
	    int v;
	    cin>>v;
	    adj[i].push_back(v);
	    adj[v].push_back(i);
	}

	int x = 0; // there will be atmax 2^x jump at once
	int tmp = n;
	while(tmp!=0){
		tmp/=2;
		x++;
	}

	vector<vector<int>> binlift(n+1,vector<int>(x+1,-1));

	binlift_dfs(adj,binlift,x,-1,1);

	vector<int> level(n+1,INT_MAX);
	level_bfs(adj,level,1);
	// peek(level)

	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<LCA2(a,b,x,binlift,level)<<"\n";
	}
	return 0;
}
