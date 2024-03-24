#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int x0,y0,x1,y1;
	cin>>x0>>y0>>x1>>y1;
	int n;
	cin>>n;
	map<int,set<int>> m;
	for(int i = 0; i<n; i++){
		int r,a,b;
		cin>>r>>a>>b;
		for(int i=a; i<=b; i++){
			m[r].insert(i);			
		}
	}
	queue<pair<int,int>> q;
	map<pair<int,int>,bool> vis;
	map<pair<int,int>,int> dis;
	q.push({x0,y0});
	vis[{x0,y0}] = true;
	int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
    int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
	while(!q.empty()){
		pair<int,int> node = q.front();
		q.pop();
		int x = node.first;
		int y = node.second;
		for(int i=0; i<8; i++){
	        int rx = x+dx[i];
	        int ry = y+dy[i];
	        if(m.find(rx)!=m.end()){
				if(m[rx].find(ry)!=m[rx].end()){
					if(!vis[{rx,ry}]){
						q.push({rx,ry});
						dis[{rx,ry}] = dis[node] + 1;
						vis[{rx,ry}] = true;
					}
				}
			}
	    }
	}
	if(dis.find(make_pair(x1,y1))!=dis.end()){
		cout<<dis[make_pair(x1,y1)]<<"\n";
	} else {
		cout<<-1<<"\n";
	}
	return 0;
}