#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

void update(vector<vector<int>> &BIT, int x, int y, int val, int n){
	while(x<=n){
		int ty = y;
		while(ty<=n){
			BIT[x][ty] += val;
			ty += ((ty)&(-ty));
		}
		x += ((x)&(-x));
	}
}
int prefix(vector<vector<int>> &BIT, int x, int y){
	int ans = 0;
	while(x>0){
		int ty = y;
		while(ty>0){
			ans += BIT[x][ty];
			ty -= ((ty)&(-ty));
		}
		x -= ((x)&(-x));
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int t;
	cin>>t;
	vector<vector<int>> BIT(n+1, vector<int>(n+1,0));
	vector<vector<char>> forest(n+1, vector<char>(n+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>forest[i][j];
			if(forest[i][j]=='*') update(BIT,i,j,1,n);
		}	
	}
	// dpeek(BIT)
	while(t--){
	int q;
	cin>>q;
	if(q==1) {
		int x,y;
		cin>>x>>y;
		if(forest[x][y]=='.') {
			update(BIT,x,y,1,n);
			forest[x][y] = '*';
		} else {
			update(BIT,x,y,-1,n);
			forest[x][y] = '.';
		}
	} else {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<prefix(BIT,x2,y2) - prefix(BIT,x1-1,y2)
		- prefix(BIT,x2,y1-1) + prefix(BIT, x1-1, y1-1)<<"\n";
	}
}
	return 0;
}