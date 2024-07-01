#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
vector<int> par;
vector<int> sz;
void make_set(int n){
	for(int i = 0; i<n; i++){
		par.push_back(i);
		sz.push_back(1);
	}
}
int find_set(int u){
	if(par[u]==u) return u;
	return par[u] = find_set(par[u]);
}
void union_set(int u, int v){
	int p1 = find_set(u);
	int p2 = find_set(v);
	if(p1==p2) return;
	if(sz[p1]>=sz[p2]) {
		sz[p1] += sz[p2];
		par[p2] = p1;
	} else {
		sz[p2] += sz[p1];
		par[p1] = p2;
	}
}
 
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges(m);
	for(int i = 0; i<m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		edges[i] = {c,{u,v}};
	}
	sort(edges.begin(), edges.end());
	make_set(n);
	int ans = 0;
	int cnt = 0;
	for(auto e : edges){
		int c = e.first;
		int u = e.second.first;
		int v = e.second.second;
		if(find_set(u)==find_set(v)) continue;
		union_set(u,v);
		ans += c;
		cnt++;
	}
	if(cnt==n-1) cout<<ans;
	else cout<<"IMPOSSIBLE";
}