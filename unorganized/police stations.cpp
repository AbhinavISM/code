#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x+1<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t = 1;
	while(t--){
	int n,k,d;
	cin>>n>>k>>d;
	vector<int> police(k);
	for(int i = 0; i<k; i++){
		cin>>police[i];
		police[i]--;
	}
	vector<vector<int>> adj(n,vector<int>());
	map<pair<int,int>, int> roadidx;
	for(int i = 0; i<n-1; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		roadidx[{u,v}] = i;
		roadidx[{v,u}] = i;
	}
	set<int> faltu;
	for(int i = 0; i<n-1; i++){
		faltu.insert(i);
	}
	vector<bool> vis(n,false);
	queue<int> q;
	for(int i = 0; i<k; i++){
		q.push(police[i]);
		vis[police[i]] = true;
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child : adj[node]){
			if(!vis[child]){
				faltu.erase(roadidx[{node,child}]);
				vis[child] = true;
				q.push(child);
			}
		}
	}
	cout<<faltu.size()<<"\n";
	peek(faltu)
}
	return 0;
}