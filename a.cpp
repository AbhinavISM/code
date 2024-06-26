#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";

void dfs(vector<bool> &vis, set<int> &comp, vector<vector<int>> &adj, map<int,int> &nodeToRegion, int &region, int node){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(vis,comp,adj,nodeToRegion,region,child);
        }
    }
    comp.insert(node);
    nodeToRegion[node] = region;
}
vector<int> solve(int n, vector<vector<int>> connections, vector<vector<int>> queries){
    vector<vector<int>> adj(n,vector<int>());
    for(auto it : connections){
        adj[it[0]-1].push_back(it[1]-1);
        adj[it[1]-1].push_back(it[0]-1);
    }
    vector<set<int>> components;
    map<int,int> nodeToRegion;
    vector<bool> vis(n,false);
    int region = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            set<int> comp;
            dfs(vis,comp,adj,nodeToRegion,region,i);
            components.push_back(comp);
            region++;
        }
    }
    vector<int> ans;
    set<int> dead;
    for(auto it : queries){
        if(it[0]==1){
            if(dead.find(it[1]-1)==dead.end()){
                ans.push_back(it[1]);
            } else if(components[nodeToRegion[it[1]-1]].size()>0){
                ans.push_back((*components[nodeToRegion[it[1]-1]].begin())+1);
            } else {
                ans.push_back(-1);
            }
        } else {
            if(components[nodeToRegion[it[1]-1]].find(it[1]-1)!=components[nodeToRegion[it[1]-1]].end()){
                components[nodeToRegion[it[1]-1]].erase(components[nodeToRegion[it[1]-1]].find(it[1]-1));
                dead.insert(it[1]-1);
            }
        }
    }
    return ans;
}

void solvee(){
    int n, m;
    cin >> n >> m;
    vector<int> cache(m);
    for (int i = 0; i < m; i++)
    {
        cin >> cache[i];
    }
    map<int, int> mp;
    for (auto it : cache)
    {
        mp[it]++;
    }
    int l = 0, r = 2 * m;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        bool flag = 1;
        int num = 0, cnt = 0;
        for (auto it : mp)
        {
            if (it.second >= mid)
            {
                cnt += it.second - mid;
            }
            num++;
        }
        if ((n - num) * mid >= 2 * cnt)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}
int32_t main(){
    int n; vector<vector<int>> connections; vector<vector<int>> queries;
    n = 2;
    connections.push_back({1,2});
    // connections.push_back({2,3});
    // connections.push_back({1,4});
    // connections.push_back({4,3});
    // queries.push_back({2,2});
    queries.push_back({1,2});
    // queries.push_back({2,1});
    // queries.push_back({2,3});
    // queries.push_back({1,1});
    peek(solve(n,connections,queries));
}