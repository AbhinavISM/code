#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<int> cost(n,0);
	vector<tuple<int,int,int>> edges(m);
	for(int i = 0; i<m; i++){
		int u,v,c;
		cin>>u>>v>>c;
		edges[i] = {u-1,v-1,c};
	}
	vector<int> relaxer(n,-1);
	int lastRelaxed = -1;
	for(int i = 0; i<n; i++){
		lastRelaxed = -1;
		for(auto e : edges){
			int u = get<0>(e);
			int v = get<1>(e);
			int c = get<2>(e);
			if(cost[u] + c < cost[v]){
				lastRelaxed = v;
				cost[v] = cost[u] + c;
				relaxer[v] = u;
			}
		}
	}
	if(lastRelaxed==-1){
		cout<<"NO";
		return 0;
	}
	int cycleElement = lastRelaxed;
	for(int i = 0; i<n; i++){
		cycleElement = relaxer[cycleElement];
	}
	vector<int> cycle;
	int ele = cycleElement;
	cycle.push_back(ele);
	ele = relaxer[ele];
	while(ele!=cycleElement){
		cycle.push_back(ele);
		ele = relaxer[ele];
	}
	cycle.push_back(cycleElement);
	reverse(cycle.begin(), cycle.end());
	cout<<"YES\n";
	peek(cycle);
}