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
	vector<int> a(n+2);
	a[0] = 1000000000000ll;
	a[n+1] = (-1ll*1000000000000ll);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	vector<int> cost(n+2,1000000000000ll);
	cost[1] = 0;
	cost[2] = 1;
	for(int i = 2; i<n; i++){
		int d1 = abs(a[i] - a[i-1]);
		int d2 = abs(a[i] - a[i+1]);
		if(d1>d2){
			cost[i+1] = cost[i] + 1;
		} else {
			cost[i+1] = cost[i] + abs(a[i+1] - a[i]);
		}
	}
	vector<int> rcost(n+2,1000000000000ll);
	rcost[n] = 0;
	rcost[n-1] = 1;
	for(int i = n-1; i>=1; i--){
		int d1 = abs(a[i]-a[i-1]);
		int d2 = abs(a[i]-a[i+1]);
		if(d1>d2){
			rcost[i-1] = rcost[i] + abs(a[i]-a[i-1]);
		} else {
			rcost[i-1] = rcost[i] + 1;
		}
	}
	int m;
	cin>>m;
	for(int i = 0; i<m; i++){
		int x,y;
		cin>>x>>y;
		if(x<y){
			cout<<cost[y] - cost[x]<<"\n";			 	
		} else {
			cout<<rcost[y] - rcost[x]<<"\n";
		}
	}
}
	return 0;
}