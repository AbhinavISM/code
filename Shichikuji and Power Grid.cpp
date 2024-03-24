#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
struct triplet {
	int u,v,w;
};
bool cmp (triplet &a, triplet &b){
	return a.w<b.w;
}
vector<int> par(2001);
vector<int> rnk(2001);
void make_set(int n){
	for(int i = 0; i<=n; i++){
		par[i] = i;
		rnk[i] = 1;
	}
}
int find_set(int a){
	if(par[a]==a){
		return a;
	}
	return par[a] = find_set(par[a]);
}
void union_set(int a, int b){
	int pa = find_set(a);
	int pb = find_set(b);
	if(pa==pb){
		return;
	}
	int ra = rnk[pa];
	int rb = rnk[pb];
	if(ra>=rb){
		par[pb] = pa;
		rnk[pa] += rnk[pb];
	} else {
		par[pa] = pb;
		rnk[pb] += rnk[pa];
	}
}
int32_t main(){
	fast_io;
	int t = 1;
	while(t--){
	int n;
	cin>>n;
	vector<pii> cities(n+1);
	for(int i = 1; i<=n; i++){
		int x,y;
		cin>>x>>y;
		cities[i] = {x,y};
	}
	vector<int> stationcost(n+1);
	for(int i = 1; i<=n; i++){
		cin>>stationcost[i];
	}
	vector<int> wirecost(n+1);
	for(int i = 1; i<=n; i++){
		cin>>wirecost[i];
	}
	vector<triplet> edges;
	for(int i = 1; i<=n; i++){
		edges.push_back({0,i,stationcost[i]});
	}
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			int len = abs(cities[i].first - cities[j].first) 
			+ abs(cities[i].second - cities[j].second);
			int cost = len*(wirecost[i] + wirecost[j]);
			edges.push_back({i,j,cost});
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	make_set(n);
	int ans = 0;
	vector<int> buildps;
	vector<vector<int>> buildwire;
	for(triplet edge : edges){
		if(find_set(edge.u)==find_set(edge.v)){
			continue;
		}
		union_set(edge.u, edge.v);
		ans += edge.w;
		if(edge.u==0){
			buildps.push_back(edge.v);
		} else {
			buildwire.push_back({edge.u, edge.v});
		}
	}
	cout<<ans<<"\n";
	cout<<buildps.size()<<"\n";
	peek(buildps)
	cout<<buildwire.size()<<"\n";
	dpeek(buildwire)
}
	return 0;
}