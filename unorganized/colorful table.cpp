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
	int k;
	cin>>k;
	map<int, pair<int, int>> colors;
	for(int i = 0; i<n; i++){
		int color;
		cin>>color;
		if(colors.find(color)==colors.end()){
			colors[color] = {i,i};
		} else {
			colors[color] = {min(i,colors[color].first), max(i,colors[color].second)};
		}
	}
	auto it = colors.rbegin();
	int lastleft = INT_MAX;
	int lastRight = INT_MIN;
	vector<int> ans(k,0);
	while(it!=colors.rend()){
		if((it->second).first<lastleft){
			lastleft = (it->second).first;
		}  if((it->second).second>lastRight){
			lastRight = (it->second).second;
		}
		ans[it->first - 1] = 2*(lastRight-lastleft+1);
		it++;
	}
	for(auto it = ans.begin(); it!=ans.end(); it++){
		cout<<(*it)<<" ";
	}
	cout<<"\n";
}
	return 0;
}