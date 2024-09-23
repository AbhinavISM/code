#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
void bfs(vector<vector<vector<pair<int,int>>>>& graph, pair<int,int> S,
	vector<vector<int>>& dist)
{
    // queue to store the nodes in the order they are
    // visited
    queue<pair<int,int>> q;
    // Mark the distance of the source node as 0
    dist[S.first][S.second] = 0;
    // Push the source node to the queue
    q.push(S);
 
    // Iterate till the queue is not empty
    while (!q.empty()) {
        // Pop the node at the front of the queue
        pair<int,int> node = q.front();
        q.pop();
 
        // Explore all the neighbours of the current node
        for (pair<int,int> neighbour : graph[node.first][node.second]) {
            // Check if the neighbouring node is not visited
            if (dist[neighbour.first][neighbour.second] == INT_MAX) {
                // Mark the distance of the neighbouring
                // node as distance of the current node + 1
                dist[neighbour.first][neighbour.second] = dist[node.first][node.second] + 1;
                // Insert the neighbouring node to the queue
                q.push(neighbour);
            }
        }
    }
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> matrix(n,vector<int>(m));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>matrix[i][j];
		}
	}
	vector<vector<vector<pair<int,int>>>> adj(n,vector<vector<pair<int,int>>>(m,vector<pair<int,int>>()));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			// if(matrix[(i+1)%n][j]==0){
			// 	adj[i][j].push_back({((i+1)%n),j});
			// }
			if(matrix[(i+1)%n][j]==0&&matrix[(i+2)%n][j]==0){
				adj[i][j].push_back({((i+2)%n),j});
			}
			if(j!=m-1){
				if(matrix[((i+1)%n)][j+1]==0){
					adj[i][j].push_back({((i+1)%n),j+1});
				}
			}
		}
	}
	vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
	dist[0][0] = 0;
	pair<int, int> S = make_pair(0,0);
	bfs(adj,S,dist);
	int ans = INT_MAX;
	for(int i = 0; i<n; i++){
		// cout<<dist[i][m-1]<<"\n";
		int k = n-1+dist[i][m-1];
		k%=n;
		ans = min(ans,(i-k+n)%n + dist[i][m-1]);
	}
	// cout<<ans<<"\n";
	cout<<((ans!=INT_MAX)?ans:-1)<<"\n";
}
	return 0;
}