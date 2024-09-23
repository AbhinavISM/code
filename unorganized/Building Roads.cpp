#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	vector<int> vis(n,false);
	vector<pair<int,int>> ans;
	for(int i = 0; i<n; i++){
		if(!vis[i]){
			if(i!=0) {ans.push_back({i-1,i});}
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int node = q.front();
				q.pop();
				vis[node] = true;
				for(int child : adj[node]){
					if(!vis[child]){
						q.push(child);
					}
				}
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
	}
}