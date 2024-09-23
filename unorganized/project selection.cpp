#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

//TOPO SORT (Its just dfs if you remove the topo vector)
//reverse the topo vector after calling function
void toposort(vector<bool> &vis, vector<int> &topo, vector<vector<int>> &adj, int node){
    vis[node] = true;
    for(int child : adj[node]){
        if(!vis[child]){
            toposort(vis,topo,adj,child);
        }
    }
    topo.push_back(node);
}

// void dfs(vector<bool> &vis, vector<int> &cmp, vector<vector<int>> &adj, int node){
//     vis[node] = true;
//     cmp.push_back(node);
//     for(int child : adj[node]){
//         if(!vis[child]){
//             dfs(vis,cmp,adj,child);
//         }
//     }
// }

int solve(int ind,vector<int> &s,vector<int> &e,vector<int> &p,set<int> &tk,vector<vector<int>> &cmp){
    if(ind==s.size()) return 0;
    vector<int> curr;
    for(auto&x:cmp){
        for(auto&y:x){
            if(y==ind){
                curr=x;
                break;
            }
        }
    }
    int f=1;
    for(auto&x:curr){
        if(x==ind) break;
        if(tk.find(ind)==tk.end()){
            f=0;
            break;
        }
    }
    int ans=0;
    int fl=1;
    if(f){
        for(auto&x:tk){
            if((s[ind]>s[x] && s[ind]<e[x]) || (e[ind]>s[x] && e[ind]<e[x])){
                fl=0;
                break;
            }
        }
        if(fl){
            tk.insert(ind);
            ans=p[ind]+solve(ind+1,s,e,p,tk,cmp);
            tk.erase(ind);
        }
    }
    ans=max(ans,solve(ind+1,s,e,p,tk,cmp));
    return ans;
}

int32_t main(){
	fast_io;
    int n;
    cin>>n;
    vector<int> s(n), e(n), p(n);
    for(int i = 0; i<n; i++){
    	cin>>s[i]>>e[i]>>p[i];	
    }
    int m;
    cin>>m;
    vector<vector<int>> adj(n,vector<int>());
    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }

    vector<bool> vis(n,false);
    vector<vector<int>> components;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            vector<int> cmp;
            toposort(vis, cmp, adj, i);
            reverse(cmp.begin(), cmp.end());
            components.push_back(cmp);
        }
    }
    // dpeek(components)
    set<int> tk;
    cout<<solve(0,s,e,p,tk,components);

}