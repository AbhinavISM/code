#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

bool isCyclic(int V,vector<vector<int>>&adj)
{
   vector<int> inDegree(
       V, 0); // stores in-degree of each vertex
   queue<int>
       q; // queue to store vertices with 0 in-degree
   int visited = 0; // count of visited vertices

   // calculate in-degree of each vertex
   for (int u = 0; u < V; u++) {
       for (auto v : adj[u]) {
           inDegree[v]++;
       }
   }

   // enqueue vertices with 0 in-degree
   for (int u = 0; u < V; u++) {
       if (inDegree[u] == 0) {
           q.push(u);
       }
   }

   // BFS traversal
   while (!q.empty()) {
       int u = q.front();
       q.pop();
       visited++;

       // reduce in-degree of adjacent vertices
       for (auto v : adj[u]) {
           inDegree[v]--;
           // if in-degree becomes 0, enqueue the
           // vertex
           if (inDegree[v] == 0) {
               q.push(v);
           }
       }
   }

   return visited != V; // if not all vertices are
                        // visited, there is a cycle
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0; i<k; i++){
		int v;
		cin>>v;
		if(n>1)cin>>v;	
		for(int j = 2; j<n; j++){
			int u;
			cin>>u;
			adj[v-1].push_back(u-1);
			v = u;
		}
	}
	if(!isCyclic(n,adj)){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}