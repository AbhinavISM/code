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
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	for(int i = 0; i<n; i++){
		string s;
		cin>>s;
		for(int j = 0; j<m; j++){
			if(s[j]=='0'){
				a[i][j] = 0;
			} else {
				a[i][j] = 1;
			}
		}
	}
	queue<pair<int,int>> q;
	vector<vector<int>> distance(n+1,vector<int>(m+1,INT64_MAX));
	vector<vector<vector<pair<int,int>>>> adj(n+1,vector<vector<pair<int,int>>>(m+1,vector<pair<int,int>>()));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(i!=0) adj[i][j].push_back({i-1,j});
			if(j!=0) adj[i][j].push_back({i,j-1});
			if(i!=n-1) adj[i][j].push_back({i+1,j});
			if(j!=m-1) adj[i][j].push_back({i,j+1});
			if(a[i][j]) {adj[n][m].push_back({i,j});}
		}
	}
	q.push({n,m});
	distance[n][m] = -1;
	while(q.size()!=0){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for(auto it : adj[a][b]){
			if(distance[it.first][it.second]==INT64_MAX){
				distance[it.first][it.second] = distance[a][b]+1;
				q.push(it);
			}
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout<<distance[i][j]<<" ";
		}
		cout<<"\n";
	}
}
	return 0;
}