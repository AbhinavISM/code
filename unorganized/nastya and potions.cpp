#include<bits/stdc++.h>
#define int long long
#define ld long double
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<int> costs(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		costs[i] = item;
	}
	for(int i = 1; i<=k; i++){
		int item;
		cin>>item;
		costs[item] = 0;
	}
	vector<vector<int>> recipies(n+1,vector<int>());
	vector<vector<int>> revadj(n+1,vector<int>());
	vector<int> indeg(n+1,0);
	for(int i = 1; i<=n; i++){
		int mi;
		cin>>mi;
		for(int j = 0; j<mi; j++){
			int parent;
			cin>>parent;
			recipies[parent].push_back(i);
			revadj[i].push_back(parent);
			indeg[i]++;
		}
	}
	queue<int> pq;
	for(int i = 1; i<=n; i++){
		if(indeg[i]==0){
			pq.push(i);
		}
	}
	vector<int> topo;
	while(!pq.empty()){
		int par = pq.front();
		pq.pop();
		topo.push_back(par);
		for(int child : recipies[par]){
			indeg[child]--;
			if(indeg[child]==0){
				pq.push(child);
			}
		}
	}
	for(int i : topo){
		int making_cost = 0;
		for(int par : revadj[i]){
			making_cost += costs[par];
		}
		if(revadj[i].size()>0) costs[i] = min(costs[i], making_cost);
	}
	bool first = true;
	for(int c : costs){
		if(first){
			first = false;
			continue;
		}
		cout<<c<<" ";
	}
	cout<<"\n";
}
	return 0;
}