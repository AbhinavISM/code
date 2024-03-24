#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n);
	for(int i = 0; i<m; i++){
		int f1,f2;
		cin>>f1>>f2;
		a[f1-1].push_back(f2-1);
		a[f2-1].push_back(f1-1);
	}
	stack<int> s;
	for(int i = 0; i<n; i++){
		s.push(i);
	}
	vector<int> team(n,0);
	int currteam = 1;
	bool good = true;
	while(!s.empty()){
		int node = s.top();
		s.pop();
		if(team[node]!=0){
			currteam = team[node];
		} else {
			team[node] = currteam;			
		}
		currteam = 3-currteam;
		for(int child : a[node]){
			if(team[child]==0){
				s.push(child);
				team[child] = currteam;
			} else if(team[child]==team[node]){
				good = false;
				cout<<"IMPOSSIBLE";
				return 0;
			}
		}
	}
	peek(team)
}
