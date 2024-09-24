#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	int t = 1;
	while(t--){
		int n;
		cin>>n;
		vector<int> x(n,0);
		for(int i = 0; i<n; i++){
			cin>>x[i];
		}
		vector<int> p(n,0);
		for(int i = 0; i<n; i++){
			cin>>p[i];
		}
		set<pair<int,int>> xp;
		for(int i = 0; i<n; i++){
			xp.insert({x[i], p[i]});
		}
		x = vector<int>();
		p = vector<int>();
		for(auto it : xp){
			x.push_back(it.first);
			p.push_back(it.second);
		}
		for(int i = 1; i<n; i++){
			p[i] += p[i-1];	
		}
		int q;
		cin>>q;
		while(q--){
			int l,r;
			cin>>l>>r;
			auto it1 = lower_bound(x.begin(), x.end(), l);
			auto it2 = upper_bound(x.begin(), x.end(), r);
			if(it2==x.begin()) {
				cout<<0<<"\n";
				continue;
			}
			it2--;
			if(it1==x.begin()) {
				cout<<p[it2-x.begin()]<<"\n";
				continue;
			}
			it1--;
			cout<<(p[it2-x.begin()] - p[it1-x.begin()])<<"\n";
		}
	}
	return 0;
}