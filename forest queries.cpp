#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,q;
	cin>>n>>q;
	vector<vector<int>> a(n+1,vector<int>(n+1,0));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			char item;
			cin>>item;
			if(item=='*') a[i][j] = 1;
		}
	}
	vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
		}
	}
	// dpeek(prefix)
	while(q--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<prefix[x2][y2] + prefix[x1-1][y1-1] - prefix[x2][y1-1] - prefix[x1-1][y2]<<"\n";
	}
	return 0;
}