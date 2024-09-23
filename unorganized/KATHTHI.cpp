#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,m;
	cin>>n>>m;
	vector<string> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	deque<pair<int,int>> q;
	vector<vector<int>> distance(n,vector<int>(m,INT64_MAX));
	q.push_back({0,0});
	distance[0][0] = 0;
	while(q.size()!=0){
		int i = q.front().first;
		int j = q.front().second;
		q.pop_front();
		int c[] = {0, -1, 0, 1};
        int b[] = {-1, 0, 1, 0};
        for(int x=0;x<4;x++){
            int tmpX = i + c[x];
            int tmpY = j + b[x];
            if(in_range(tmpX, tmpY, n, m)){
				if((a[i][j]==a[tmpX][tmpY])&&distance[tmpX][tmpY]>distance[i][j]){
					distance[tmpX][tmpY] = distance[i][j];
					q.push_front({tmpX, tmpY});
				} else if(distance[tmpX][tmpY]>distance[i][j] + 1){
					distance[tmpX][tmpY] = distance[i][j] + 1;
					q.push_back({tmpX,tmpY});
				}		
			}
		}
	}
	// dpeek(distance)
	cout<<distance[n-1][m-1]<<"\n";
}
	return 0;
}