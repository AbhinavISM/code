#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set

struct edge{
	int u, v, s, t, idx, x;
	bool operator<(const edge& other) const {
        if (u != other.u) return u < other.u;
        if (v != other.v) return v < other.v;
        if (s != other.s) return s < other.s;
        if (t != other.t) return t < other.t;
        if (idx != other.idx) return idx < other.idx;
        return x < other.x;
    }
};
int32_t main(){
	fast_io;
	int t;
	t = 1;
	while(t--){
		int n,m,x0;
		cin>>n>>m>>x0;
		vector<edge> edges;
		vector<vector<int>> a(n, vector<int>());
		for(int i = 0; i<m; i++){
			int u, v, s, t;
			cin>>u>>v>>s>>t;
			u--; v--;
			a[u].push_back(i);
			edges.push_back({u,v,s,t,i,0});
		}
		edges[0].x = x0;
		queue<edge> q;
		q.push(edges[0]);
		while(!q.empty()){
			edge e1 = q.front();
			q.pop();
			for(int child : a[e1.v]){
				edge e2 = edges[child];
				// cout<<e1.t<<" "<<e2.s<<" ";
				// cout<<e1.t+e1.x<<" "<<e2.s+e2.x<<"\n";
				if(e2.s>=e1.t){
					if(e2.s+e2.x<e1.t+e1.x){
						e2.x += (e1.t+e1.x-e2.s-e2.x);
						edges[child] = e2;
						q.push(edges[child]);
					}
				}
			}
		}
		for(int i = 1; i<m; i++){
			cout<<edges[i].x<<" ";
		}
	}
	return 0;
}