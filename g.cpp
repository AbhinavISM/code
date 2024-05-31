#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i : v) {for(auto j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<vector<string>> a(n,vector<string>(2));
	for(int i = 0; i<n; i++){
		cin>>a[i][0];
		cin>>a[i][1];
	}
	int ans = n;
	for(int mask = 1; mask < (1 << n); mask++) {
		vector<vector<string>> ta;
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) {
				ta.push_back(a[i]);
			}
		}
		map<pair<string,string>, vector<pair<string,string>>> graph;
		for(int i = 0; i<ta.size(); i++){
			for(int j = i; j<ta.size(); j++){
				if(a[i][0]==a[j][0]||a[i][1]==a[j][1]){
					graph[{a[i][0],a[i][1]}].push_back({a[j][0],a[j][1]});
					graph[{a[j][0],a[j][1]}].push_back({a[i][0],a[i][1]});
				}
			}
		}
		map<pair<string,string>,bool> vis;
		for(auto node : ta){
			vis[{node[0],node[1]}] = false;
		}
		queue<pair<string,string>> q;
		q.push({ta[0][0],ta[0][1]});
		vis[{ta[0][0],ta[0][1]}] = true;
		while(!q.empty()){
		    pair<string,string> node = q.front();
		    q.pop();
		    for(auto child : graph[node]){
		        if(!vis[child]){
		            vis[child] = true;
		            q.push(child);
		        }
		    }
		}
		bool good = true;
		for(auto it : vis){
			if(!it.second){
				good = false;
			}
		}
		if(good){
			ans = min(ans,n-ta.size());
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}