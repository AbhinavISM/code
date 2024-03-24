#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<pair<int,int>> pts;
	set<pair<int,int>> s;
	for(int i = 0; i<n; i++){
		int x,y;
		cin>>x>>y;
		pts.push_back({x,y});
		s.insert({x,y});
	}
	sort(pts.begin(), pts.end());
	int ans = 0;
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			int nx = pts[i].first + pts[j].first;
			int ny = pts[i].second + pts[j].second;
			if((abs(nx)%2==1)||(abs(ny)%2==1)){
				continue;
			}
			auto midit = (s.find({(nx/2), (ny/2)}));
			if(midit!=s.end()){
				ans++;
			}
		}
	}
	cout<<ans;
}