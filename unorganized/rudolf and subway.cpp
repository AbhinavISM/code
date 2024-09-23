#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	map<int,int> colormap;
	int colornum = n;
	vector<vector<pair<int,int>>> adj(2*n,vector<pair<int,int>>());
	for(int i = 0; i<m; i++){
	    int u,v,c;
	    cin>>u>>v>>c;
	    if(colormap.find(c)==colormap.end()){
	    	colormap[c] = colornum;
	    	colornum++;
	    }
	    adj[u-1].push_back({v-1,colormap[c]});
	    adj[v-1].push_back({u-1,colormap[c]});
	    adj[colormap[c]].push_back({v-1,colormap[c]});
	    adj[colormap[c]].push_back({u-1,colormap[c]});
	}
}
	return 0;
}