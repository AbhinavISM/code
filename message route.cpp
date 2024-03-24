#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define pb push_back
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<m; i++){
		int a,b;
		cin>>a>>b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	vector<int> distance(n,INT64_MAX);
	queue<int> q;
	q.push(0);
	distance[0] = 0;
	vector<int> parent(n,-1);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child : adj[node]){
			if(distance[child]==INT64_MAX){
				distance[child] = distance[node] + 1;
				q.push(child);
				parent[child] = node;
			}
		}
	}
	if(distance[n-1]==INT64_MAX){
		cout<<"IMPOSSIBLE";
	} else {
		cout<<distance[n-1]+1<<"\n";
		stack<int> path;
		path.push(n-1);
		while(path.top()!=-1){
			path.push(parent[path.top()]);
		}
		path.pop();
		while(!path.empty()){
			cout<<path.top()+1<<" ";
			path.pop();
		}
	}
}