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
struct triplet{
	int u,v,w;
};
void floydWarshall(int n, vector<vector<int>> &dp){
	for(int k=0; k<n; k++){
	    for(int i=0; i<n; i++){   
	        for(int j=0; j<n; j++){
	            dp[i][j]  = min(dp[i][j], dp[i][k] + dp[k][j]);
	        }
	    }
	}
}
void generateAllPrem(int i, int m, vector<triplet> &perm, vector<vector<triplet>> &allPrem){
	if(i==m) {
		allPrem.push_back(perm);
		return;
	}
	for(int j = i; j<m; j++){
		swap(perm[i], perm[j]);
		generateAllPrem(i+1, m, perm, allPrem);
		swap(perm[i], perm[j]);
	}
}
int32_t main(){
	fast_io;
	int t;
	t = 1;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> dp(n,vector<int>(n,1e17));
		for(int i = 0; i<n; i++){
			dp[i][i] = 0;
		}
		vector<triplet> edges(m);
		for(int i = 0; i<m; i++){
		    int u,v,w;
		    cin>>u>>v>>w;
		    dp[u-1][v-1] = min(dp[u-1][v-1], w);
		    dp[v-1][u-1] = min(dp[v-1][u-1], w);
		    edges[i] = {u-1, v-1, w};
		}
		floydWarshall(n, dp);
		int q;
		cin>>q;
		while(q--){
			int k;
			cin>>k;
			vector<triplet> must;
			for(int i = 0; i<k; i++){
				int b; cin>>b; b--;
				must.push_back(edges[b]);
			}
			int ans = INT64_MAX;
			vector<vector<triplet>> allPrem;
			generateAllPrem(0,k,must,allPrem);
			for(vector<triplet> perm : allPrem){
				perm.push_back({n-1, n-1, 0});
				for(int mask = 0; mask<(1<<k); mask++){
					int tans = 0;
					bool lo = 0;
					triplet ln = {0,0,0};
					for(int i = 0; i<k+1; i++){
						tans += perm[i].w;
						if(mask&(1<<i)){
							if(lo){
								tans += min({
								dp[ln.v][perm[i].u],
								dp[ln.u][perm[i].u]+dp[ln.u][ln.v]
								});
							} else{
								tans += min({
								dp[ln.v][perm[i].u]+dp[ln.u][ln.v],
								dp[ln.u][perm[i].u]
								});
							}
						} else {
							if(lo){
								tans += min({
								dp[ln.v][perm[i].v],
								dp[ln.u][perm[i].v]+dp[ln.u][ln.v]
								});
							} else{
								tans += min({
								dp[ln.v][perm[i].v]+dp[ln.u][ln.v],
								dp[ln.u][perm[i].v]
								});
							}
						}
						lo = mask&(1<<i);
						ln = perm[i];
					}
					ans = min(ans, tans);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}