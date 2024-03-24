#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<string> matrix(n);
	for(int i = 0; i<n; i++){
		cin>>matrix[i];
	}
	pair<int,int> start;
	pair<int,int> end;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(matrix[i][j]=='A'){
				start = {i,j};
				matrix[i][j] = '.';
			} else if(matrix[i][j]=='B'){
				end = {i,j};
				matrix[i][j] = '.';
			}
		}
	}
	queue<pair<int,int>> q;
	q.push(start);
	vector<vector<int>> distance(n+1,vector<int>(m+1,INT64_MAX));
	distance[start.first][start.second] = 0;
	vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
	while(q.size()!=0){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
    		int rx = x+dx[i];
    		int ry = y+dy[i];
    		if(rx>=0&&rx<n&&ry>=0&&ry<m){
    			if(matrix[rx][ry]=='.'&&distance[rx][ry]==INT64_MAX){
    				q.push({rx,ry});
    				distance[rx][ry] = distance[x][y] + 1;
    				parent[rx][ry] = {x,y};
    			}
    		}
		}
	}
	if(distance[end.first][end.second]!=INT64_MAX) {
		cout<<"YES\n";
		cout<<distance[end.first][end.second]<<"\n";
		stack<pair<int,int>> path;
		path.push(end);
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
