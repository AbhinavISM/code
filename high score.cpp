#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
	vector<tuple<int,int,int>> edges;
	for(int i = 0; i<m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u-1].push_back({v-1,c});
		edges.push_back({u-1,v-1,c});
	}
	vector<int> dis(n,INT_MIN);
	dis[0] = 0;
	int r1;
	for(int i = 0; i<=2*n; i++){
		if(i==n) r1 = dis[n-1];
		for(auto e : edges){
			int u = get<0>(e);
			int v = get<1>(e);
			int c = get<2>(e);
			if(i>=n){
				if(dis[u]==INT64_MAX) {
					dis[v] = INT64_MAX;
				} else if(dis[u]!=INT_MIN&&dis[v]<dis[u]+c) {
					dis[v] = INT64_MAX;
				}
			} else {
				if(dis[u]!=INT_MIN&&dis[v]<dis[u]+c) {
					dis[v] = dis[u] + c;
				}
			}
		}
	}
	if(dis[n-1]==r1&&dis[n-1]!=INT_MIN) cout<<dis[n-1];
	else cout<<-1;
}