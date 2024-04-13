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
	int t;
	cin>>t;
	while(t--){
	int n,k,a,b;
	cin>>n>>k>>a>>b;
	vector<pii> cities(n);
	for(int i = 0; i<n; i++){
		int x,y;
		cin>>x>>y;
		cities[i] = {x,y};
	}
	int a1 = (abs(cities[a-1].first - cities[b-1].first) 
	+ abs(cities[a-1].second - cities[b-1].second));
	if(k==0) {
		cout<<a1<<"\n";
		continue;
	}
	int a2 = INT64_MAX;
	for(int i = 1; i<=k; i++){
		a2 = min(a2, (abs(cities[a-1].first - cities[i-1].first) 
	+ abs(cities[a-1].second - cities[i-1].second)));
	}
	int a3 = INT64_MAX;
	for(int i = 1; i<=k; i++){
		a3 = min(a3, (abs(cities[i-1].first - cities[b-1].first) 
	+ abs(cities[i-1].second - cities[b-1].second)));
	}
	cout<<min(a1,a2+a3)<<"\n";
}
	return 0;
}