#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int>> adj(n,vector<int>(n,10000000000000ll));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(i==j)adj[i][j] = 0;
		}
	}
	for(int i = 0; i<m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u-1][v-1] = min(adj[u-1][v-1],c);
		adj[v-1][u-1] = min(adj[v-1][u-1],c);
	}
	for(int k=0; k<n; k++){
    	for(int i=0; i<n; i++){	
			for(int j=0; j<n; j++){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		if(adj[a-1][b-1]==10000000000000ll) cout<<-1<<"\n";
		else cout<<adj[a-1][b-1]<<"\n";
	}
}