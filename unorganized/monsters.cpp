#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x,y,r,c) x<r&&x>=0&&y<c&&y>=0
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<string> matrix(n);
	for(int i = 0; i<n; i++){
		cin>>matrix[i];
	}
	pair<int,int> goodSource;
	queue<pair<int,int>> q;
	vector<vector<int>> distance(n+1,vector<int>(m+1,INT64_MAX));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(matrix[i][j]=='M'){
				q.push({i,j});
				distance[i][j] = 0;
			}
			if(matrix[i][j]=='A'){
				goodSource = {i,j};
			}
		}
	}
	while(q.size()!=0){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++){
			int tx = a + dx[i];
			int ty = b + dy[i];
			if(in_range(tx,ty,n,m)&&matrix[tx][ty]!='#'&&distance[tx][ty]==INT64_MAX){
				distance[tx][ty] = distance[a][b]+1;
				q.push({tx,ty});
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
		for(int i = 0; i<4; i++){
			int tx = a + dx[i];
			int ty = b + dy[i];
			if(in_range(tx,ty,n,m)&&matrix[tx][ty]!='#'&&distance[tx][ty]>distance[a][b]+1){
				distance[tx][ty] = distance[a][b]+1;
				q.push({tx,ty});
				parent[tx][ty] = {a,b};
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