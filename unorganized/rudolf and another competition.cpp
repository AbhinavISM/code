#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool cmp(pair<int, int>&first, pair<int, int>&second){
	if(first.first>second.first){
		return true;
	} else if(first.first==second.first){
		if(first.second<=second.second){
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	int h;
	cin>>h;
	vector<vector<int>> participants(n,vector<int>(m));
	vector<int> rudolf(m);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			int time;
			cin>>time;
			participants[i][j] = time;
			if(i==0){
				rudolf[j] = time;
			}
		}
	}
	vector<pair<int, int>> ans(n);
	for(int i = 0; i<n; i++){
		int points = 0;
		int penalty = 0;
		int mytime = h;
		sort(participants[i].begin(), participants[i].end());
		for(int j = 0; j<m; j++){
			if(mytime>=participants[i][j]){
				points++;
				mytime -= participants[i][j];
				penalty = 2*penalty + participants[i][j];
			}
		}
		ans[i] = make_pair(points, penalty);
	}
	pair<int,int> rudolfans = ans[0];
	sort(ans.begin(), ans.end(),cmp);
	for(int i = 0; i<n; i++){
		if(rudolfans.first==ans[i].first){
			if(rudolfans.second==ans[i].second){
				cout<<i+1<<"\n";
				return;
			}
		}
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	solve();
}
	return 0;
}