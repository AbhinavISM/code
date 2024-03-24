#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
vector<int> par(100001);
vector<int> rnk(100001);
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
	par[a] = find_set(par[a]);
	return par[a];
}

void union_set(int a, int b){
	int p1 = find_set(a);
	int p2 = find_set(b);
	if(p1==p2){
		return;
	}
	if(rnk[p1]>=rnk[p2]){
		par[p2] = p1;
		rnk[p1] += rnk[p2];
	} else {
		par[p1] = p2;
		rnk[p2] += rnk[p1];
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
	for(int i = 0; i<m; i++){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int pu = find_set(u);
		int pv = find_set(v);
		if(pu!=pv){
			union_set(pu,pv);
			ans += edges[i].first;
		}
	}
	set<int> parents;
	for(int i = 1; i<=n; i++){
		parents.insert(find_set(i));
	}
	if(parents.size()>1){
		cout<<"IMPOSSIBLE";
	} else {
		cout<<ans;		
	}
}