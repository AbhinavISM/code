#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

bool in_range(int x, int y, int r, int c) {
	return (x >= 0 && x < r && y >= 0 && y < c);
}

int32_t main(){
	fast_io;
	int n,m,q;
	cin>>n>>m>>q;
	vector<set<int>> rows(n, set<int>());
	vector<set<int>> cols(m, set<int>());
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			rows[i].insert(j);
			cols[j].insert(i);
		}
	}
	int ans = n*m;
	for(int i = 0; i<q; i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		if(rows[x].find(y)!=rows[x].end()){
			rows[x].erase(y);
			cols[y].erase(x);
			ans--;
		} else {
			if(rows[x].size()!=0){
				auto lb = rows[x].lower_bound(y);
				auto ub = rows[x].upper_bound(y);
				if(lb!=rows[x].begin()){
					lb--;
					cols[*lb].erase(x);
					rows[x].erase(lb);
					ans--;
				}
				if(ub!=rows[x].end()){
					cols[*ub].erase(x);
					rows[x].erase(ub);
					ans--;
				}
			}
			if(cols[y].size()!=0){
				auto lb = cols[y].lower_bound(x);
				auto ub = cols[y].upper_bound(x);
				if(lb!=cols[y].begin()){
					lb--;
					rows[*lb].erase(y);
					cols[y].erase(lb);
					ans--;
				}
				if(ub!=cols[y].end()){
					rows[*ub].erase(y);
					cols[y].erase(ub);
					ans--;
				}
			}
		}
	}
	cout<<ans<<" ";
	return 0;
}