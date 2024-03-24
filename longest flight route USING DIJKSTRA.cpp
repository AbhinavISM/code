#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
 
int32_t main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i = 0; i<m; i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	vector<int> parent(n+1,-1);
	vector<int> cost(n+1,0);
	cost[1] = 1;
 
	queue<int> pq;
	pq.push(1);
	while(!pq.empty()){
		int node = pq.front();
		pq.pop();
		for(int child : adj[node]){
			if(cost[node] + 1 > cost[child]){
				cost[child] = cost[node] + 1;
				pq.push(child);
				parent[child] = node;
			}
		}
	}
 
	if(cost[n]==0)cout<<"IMPOSSIBLE\n";
	else {cout<<(cost[n])<<"\n";
		stack<int> path;
		path.push(n);
		while(path.top()!=-1){
			path.push(parent[path.top()]);
		}
		path.pop();
		while(!path.empty()){
			cout<<path.top()<<" ";
			path.pop();
		}	
	}
	return 0;
}