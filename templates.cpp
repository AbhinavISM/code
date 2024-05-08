#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

//comparators MUST return false for equality case
//comparators ka funda simple : jo chahiye, uske liye true return karo
bool cmp (pair<int , int> &one, pair<int , int> &two){
    //decreasing order by first value of pair
    //increasing order by second value of pair  
    if(one.first > two.first){
        return true;
    } else if(one.first < two.first){
        return false;
    } else {
        if(one.second < two.second){
            return true;
        } else {
            return false;
        }
    }
}
struct CustomComparator {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        // Sorting in decreasing order by the first value (a.first) and increasing order by the second value (a.second)
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

//GRAPH INPUT
int n,m;
cin>>n>>m;
vector<vector<int>> adj(n,vector<int>());
for(int i = 0; i<m; i++){
    int u,v;
    cin>>u>>v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

// BFS
//dis for all source nodes are set to zero already
queue<int> q;
vector<int> dis(n,INT_MAX);
q.push(src); dis[src] = 0;
while(!q.empty()){
    int node = q.front();
    q.pop();
    for(int child : adj[node]){
        if(dis[child]==INT_MAX){
            dis[child] = dis[node] + 1;
            q.push(child);
        }
    }
}

//TOPO SORT (Its just dfs if you remove the topo vector)
//reverse the topo vector after calling function
vector<bool> vis(n,false);
vector<int> topo;
void toposort(vector<bool> &vis, vector<int> &topo, vector<vector<int>> &adj, int node){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            toposort(vis,topo,adj,child);
        }
    }
    topo.push_back(node);
}

// moving all 8 adjacent coordinates
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
for(int i=0; i<8; i++){
    int rx = x+dx[i];
    int ry = y+dy[i];
}

//DSU
vector<int> par(100001);
vector<int> rnk(100001);
void make_set(int n){
    for(int i = 0; i<=n; i++){
        par[i] = i;
        rnk[i] = 1;
    }
}
int find_set(int a){
    if(par[a]==a){
        return a;
    }
    par[a] = find_set(par[a]);
    return par[a];
}

void union_set(int a, int b){
    int p1 = find_set(a);
    int p2 = find_set(b);
    if(p1==p2){
        return;
    }
    if(rnk[p1]>=rnk[p2]){
        par[p2] = p1;
        rnk[p1] += rnk[p2];
    } else {
        par[p1] = p2;
        rnk[p2] += rnk[p1];
    }
}
// NOTE: for any set top node of that set has correct information,
// So for questions like what is the size of set which contains node ‘x’
// ans will be sz[find_set(x)]

//KRUSKAL MST
sort(edges.begin(), edges.end());
make_set(n);
int cost = 0;
int edge_cnt = 0;
for(int i = 0; i<m; i++){
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    int pu = find_set(u);
    int pv = find_set(v);
    if(pu!=pv){
        union_set(pu,pv);
        cost += edges[i].first;
        edge_cnt++;
    }
}
//edge_cnt must be equal to n-1 at end, or no MST exist (disconnected graph)

//TREE DIAMETER question search kr le
int tree_diameter(int n, vector<vector<int>> &adj){
    vector<int> dis(n,INT_MAX);
    dis[0] = 0;
    dfs(0,adj,dis);
    
    int newsrc;
    int maxdis = 0;
    for(int i = 0; i<n; i++){
        maxdis = max(maxdis, dis[i]);
        if(maxdis==dis[i]){
            newsrc = i;
        }
    }

    dis = vector<int>(n,INT_MAX);
    dis[newsrc] = 0;
    dfs(newsrc,adj,dis);
    
    int diam = 0;
    for(int i = 0; i<n; i++){
        diam = max(diam, dis[i]);
    }
    return diam;
}

//build DAG using SCC (search capital city question)
int32_t main(){
    //INPUT
    fast_io;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>());
    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }
    //TOPO SORT
    stack<int> topo;
    vector<bool> vis(n,false);
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            toposort(vis,topo,adj,i);
        }
    }
    //REVERSE THE GRAPH
    vector<vector<int>> newadj(n,vector<int>());
    for(int i = 0; i<n; i++){
        for(int child : adj[i]){
            newadj[child].push_back(i);
        }
    }
    //FIND SCC BY DFS IN TOPO ORDER
    vis = vector<bool>(n,false);
    vector<vector<int>> scc;
    vector<int> component;
    while(!topo.empty()){
        int i = topo.top();
        topo.pop();
        if(!vis[i]){
            dfs(vis,component,newadj,i);
        }
        if(component.size()>0)scc.push_back(component);
        component = vector<int>();
    }
    //MARK ORIGINAL NODES BY ITS SCC NUMBER
    vector<int> sccarr(n);
    int scccnt = 0;
    for(auto it : scc){
        for(auto node : it){
            sccarr[node] = scccnt;
        }
        scccnt++;
    }
    //scccnt is exactly equal to scc.size()
    //FIND THE DAG FROM ORIGINAL GRAPH
    vector<vector<int>> dag(scccnt, vector<int>());
    for(int i = 0; i<n; i++){
        for(int child : adj[i]){
            dag[sccarr[i]].push_back(sccarr[child]);
        }
    }
}

// BINARY LIFTING QUERIES (kth parent queries)
// -> COMPANY QUERIES 1
// LCA QUERIES (O(logn*logn)) and (O(logn))
// -> COMPANY QUERIES 2
// DISTANCE BTW NODES QUERIES
// -> DISTANCE QUERIES

// SPARSE TABLE RANGE SUM (SAME AS BINARY LIFTING) (SEARCH THIS NAME!)