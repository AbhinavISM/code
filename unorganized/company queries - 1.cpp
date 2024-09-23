#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

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

	while(q--){
		int s,k;
		cin>>s>>k;
		cout<<lift_node(s,k,x,binlift)<<"\n";
	}
	
	return 0;
}
