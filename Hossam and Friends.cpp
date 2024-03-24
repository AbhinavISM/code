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
	int m;
	cin>>m;
	map<int,int> mp;
	for(int i = 0; i<m; i++){
		int x,y;
		cin>>x>>y;
		if(mp[x]==0&&y>x){
			mp[x] = y;
		} else if(y>x){
			mp[x] = min(mp[x],y);
		}
		if(mp[y]==0&&x>y){
			mp[y] = x;
		} else if(x>y){
			mp[y] = min(mp[y],x);
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(mp[i]==0){
			mp[i] = n+1;
		}
	}
	int mini = n+1;
	for(int i = n-1; i>=1; i--){
		mp[i] = min(mp[i+1], mp[i]);
	}
	for(int i = 1; i<=n; i++){
		ans += (mp[i] - i);
	}
	cout<<ans<<"\n";
}
	return 0;
} 