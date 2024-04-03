#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void dfs(vector<bool> &vis, vector<int> &comp,
 vector<set<int>> &adj, int node){
    vis[node] = true;
    comp.push_back(node);
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(vis,comp,adj,child);
        }
    }
}
int32_t main(){
	fast_io;
	int n,m,k;
	cin>>n>>m>>k;
	set<int> capitals;
	for(int i = 0; i<k; i++){
		int capital;
		cin>>capital;
		capitals.insert(capital-1);
	}
	vector<set<int>> graph(n,set<int>());
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		graph[u-1].insert(v-1);
		graph[v-1].insert(u-1);
	}
	vector<vector<int>> components;
	vector<int> nocap;
	vector<bool> vis(n,false);
	for(int i = 0; i<n; i++){
		if(!vis[i]){
			vector<int> comp;
			dfs(vis,comp,graph,i);
			bool iscap = false;
			for(int node : comp){
				if(capitals.find(node)!=capitals.end()) iscap = true;
			}
			if(iscap){
				components.push_back(comp);
			} else {
				for(int node : comp){
					nocap.push_back(node);
				}	
			}
		}
	}
	int maxcompsize = components[0].size();
	int maxcompnum = 0;
	for(int i = 1; i<components.size(); i++){
		if(components[i].size()>maxcompsize){
			maxcompsize = components[i].size();
			maxcompnum = i;
		} else if(components[i].size()==maxcompsize){
			int e1 = 0;
			int e2 = 0;
			for(int node : components[i]){
				for(int child : components[i]){
					if(graph[node].find(child)!=graph[node].end()){
						e1++;
					}
				}
			}
			for(int node : components[maxcompnum]){
				for(int child : components[maxcompnum]){
					if(graph[node].find(child)!=graph[node].end()){
						e2++;
					}
				}
			}
			if(e1<e2){
				maxcompsize = components[i].size();
				maxcompnum = i;
			}
		}
	}
	for(int city : nocap){
		components[maxcompnum].push_back(city);
	}
	// dpeek(components)
	vector<pii> edges;
	for(auto comp : components){
		for(int node : comp){
			for(int child : comp){
				if(graph[node].find(child)==graph[node].end()){
					if(node!=child){
						edges.push_back({node,child});
						graph[node].insert(child);
						graph[child].insert(node);
					}
				}
			}
		}
	}
	cout<<edges.size()<<"\n";
}