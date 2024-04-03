#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<vector<pii>> tree(n,vector<pii>());
	for(int i = 1; i<=n-1; i++){
		int v,c;
		cin>>v>>c;
		tree[i].push_back({v-1,c});
		tree[v-1].push_back({i,c});
	}
	vector<int> max_dis(n,-1*(1e15));
	vector<int> par(n,-1);
	queue<int> q;
	q.push(0);
	max_dis[0] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(pii e : tree[node]){
			int child = e.first;
			int ecost = e.second;
			if(max_dis[child]==-1*(1e15)){
				if(max_dis[node] + ecost >= 0) max_dis[child] = max_dis[node] + ecost;
				else max_dis[child] = 0;
				par[child] = node;
				q.push(child);
			}
		}
	}
	// peek(max_dis)
	vector<bool> vis(n,false);
	for(int i = 0; i<n; i++){
		if(max_dis[i]>a[i]&&(!vis[i])){
			queue<int> q;
			q.push(i);
			vis[i] = true;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				for(pii e : tree[node]){
					int child = e.first;
					if(!vis[child]&&par[node]!=child){
						vis[child] = true;
						q.push(child);
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(vis[i]) ans++;
	}
	cout<<ans;
}