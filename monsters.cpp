#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<string> matrix(n);
	for(int i = 0; i<n; i++){
		cin>>matrix[i];
	}
	pair<int,int> goodSource;
	vector<vector<vector<pair<int,int>>>> adj(n+1,vector<vector<pair<int,int>>>(m+1,vector<pair<int,int>>()));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(i!=0&&matrix[i-1][j]!='#') adj[i][j].push_back({i-1,j});
			if(j!=0&&matrix[i][j-1]!='#') adj[i][j].push_back({i,j-1});
			if(i!=n-1&&matrix[i+1][j]!='#') adj[i][j].push_back({i+1,j});
			if(j!=m-1&&matrix[i][j+1]!='#') adj[i][j].push_back({i,j+1});
			if(matrix[i][j]=='M'){
				adj[n][m].push_back({i,j});
			}
			if(matrix[i][j]=='A'){
				goodSource = {i,j};
			}
		}
	}
	queue<pair<int,int>> q;
	vector<vector<int>> distance(n+1,vector<int>(m+1,INT64_MAX));
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
	q.push(goodSource);
	distance[goodSource.first][goodSource.second] = 0;
	vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
	bool ans = false;
	pair<int,int> finalNode;
	while(q.size()!=0){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if(a==0||a==n-1||b==0||b==m-1){
			ans = true;
			finalNode = {a,b};
			break;
		}
		for(auto it : adj[a][b]){
			if(distance[it.first][it.second]>distance[a][b] + 1){
				distance[it.first][it.second] = distance[a][b]+1;
				q.push(it);
				parent[it.first][it.second] = {a,b};
			}
		}
	}
	if(ans) {
		cout<<"YES\n";
		cout<<distance[finalNode.first][finalNode.second]<<"\n";
		stack<pair<int,int>> path;
		path.push(finalNode);
		while(path.top().first!=-1){
			pair<int,int> baap = parent[path.top().first][path.top().second];
			path.push(baap);
		}
		path.pop();
		pair<int,int> baap = path.top();
		path.pop();
		while(!path.empty()){
			pair<int,int> child = path.top();
			path.pop();
			if(baap.first>child.first) cout<<'U';
			if(baap.first<child.first) cout<<'D';
			if(baap.second>child.second) cout<<'L';
			if(baap.second<child.second) cout<<'R';
			baap = child;
		}
	}
	else {cout<<"NO\n";}
	return 0;
}