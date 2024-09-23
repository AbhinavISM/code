#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void dfs(vector<vector<int>> &adj, vector<int> &lvl, int node, int par){
	for(int child : adj[node]){
		if(child!=par){
		lvl[child] = lvl[node] + 1;
			dfs(adj,lvl,child,node);
		}
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<n-1; i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u-1].push_back(v-1);
	    adj[v-1].push_back(u-1);
	}
	vector<int> lvl(n,-1);
	lvl[0] = 1;
	dfs(adj,lvl,0,-1);
	// peek(lvl)
	map<int,vector<int>> lvlmap;
	for(int i = 0; i<n; i++){
		lvlmap[lvl[i]].push_back(i);
	}
	// for(auto it : lvlmap){
	// 	cout<<it.first<<" ";
	// 	peek(it.second)
	// }
	vector<int> ans(n,-1);
	bool firstit = true;
	int lastredcnt = 0;
	int lastbluecnt = 0;
	for(auto it : lvlmap){
		bool red = true;
		if(!firstit){
			if(lastredcnt>lastbluecnt&&it.second.size()%2==1){
				red = false;
			}
			lastredcnt = 0;
			lastbluecnt = 0;
		}
		firstit = false;
		int levelofnode = it.first;
		for(int node : it.second){
			if(red) {
				ans[node] = 1;
				red = false;
				lastredcnt++;
			} else {
				ans[node] = 0;
				red = true;
				lastbluecnt++;
			}
		}
	}
	for(int color : ans){
		if(color==1) cout<<"R";
		else cout<<"B";
	}
	cout<<"\n";
}
	return 0;
}