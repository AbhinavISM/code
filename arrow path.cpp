#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	vector<vector<vector<pair<int,int>>>> graph(2,vector<vector<pair<int,int>>>(n,vector<pair<int,int>>()));
	for(int i = 0; i<2; i++){
		for(int j = 0; j<n; j++){
			if(j-1>=0) {
				if(i==0){
					if(s1[j-1]=='<'){
						if(j-2>=0){
							graph[i][j].push_back({i,j-2});
						}
					}
				}
				if(i==1){
					if(s2[j-1]=='<'){
						if(j-2>=0){
							graph[i][j].push_back({i,j-2});
						}
					}
				}
			}
			if(j+1<n){
				if(i==0){
					if(s1[j+1]=='>'){
						if(j+2<n){
							graph[i][j].push_back({i,j+2});
						}
					}
				}
				if(i==1){
					if(s2[j+1]=='>'){
						if(j+2<n){
							graph[i][j].push_back({i,j+2});
						}
					}
				}
			}
			if(i==0){
				if(s2[j]=='<'){
					if(j-1>=0){
						graph[i][j].push_back({i+1,j-1});
					}
				}
				if(s2[j]=='>'){
					if(j+1<n){
						graph[i][j].push_back({i+1,j+1});
					}
				}
			}
			if(i==1){
				if(s1[j]=='<'){
					if(j-1>=0){
						graph[i][j].push_back({i-1,j-1});
					}
				}
				if(s1[j]=='>'){
					if(j+1<n){
						graph[i][j].push_back({i-1,j+1});
					}
				}
			}
		}
	}
	for(int i = 0; i<2; i++){
		for(int j = 0; j<n; j++){
			// cout<<"child of : "<<i<<" "<<j<<"\n";
			for(auto child : graph[i][j]){
				// cout<<child.first<<" "<<child.second<<"\n";
			}
		}
	}
	vector<vector<int>> dis(2,vector<int>(n,INT64_MAX));
	queue<pair<int,int>> q;
	q.push({0,0});
	dis[0][0] = 0;
	while(!q.empty()){
	    pair<int,int> node = q.front();
	    q.pop();
		// cout<<"child of : "<<node.first<<" "<<node.second<<"\n";
	    for(pair<int,int> child : graph[node.first][node.second]){
	        if(dis[child.first][child.second]==INT64_MAX){
				// cout<<child.first<<" "<<child.second<<"\n";
	            dis[child.first][child.second] = dis[node.first][node.second] + 1;
	            q.push(child);
	        }
	    }
	}
	if(dis[1][n-1]!=INT64_MAX) cout<<"YES\n";
	else cout<<"NO\n";
	// dpeek(dis)
}
	return 0;
}