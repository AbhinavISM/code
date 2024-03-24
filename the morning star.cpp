#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	map<int,int> yplusx;
	map<int,int> yminusx;
	map<int,int> xfreq;
	map<int,int> yfreq;
	vector<pair<int,int>> coordinates;
	for(int i = 0; i<n; i++){
		int x;
		cin>>x;
		int y;
		cin>>y;
		yplusx[x+y]++;
		yminusx[y-x]++;
		xfreq[x]++;
		yfreq[y]++;
		coordinates.push_back({x,y});
	}
	int ans = 0;
	for(auto cord : coordinates){
		ans+=yplusx[cord.first+cord.second];
		ans+=yminusx[cord.second-cord.first];
		ans+=xfreq[cord.first];
		ans+=yfreq[cord.second];
		ans-=4;
	}
	cout<<ans<<"\n";
}
	return 0;
}