#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j+1<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n,d,h;
	cin>>n>>d>>h;
	if(d<h||d+1>n||d-h>h){
		cout<<-1;
		return 0;
	}
	if(d==h){
		if(n>d+1&&n<3){
			cout<<-1;
			return 0;
		}
	}
	vector<pair<int,int>> edges;
	int num = 0;
	for(int i = 0; i<h; i++){
		edges.push_back({num,num+1});
		num++;
	}
	for(int i = 0; i<d-h; i++){
		if(i==0){
			edges.push_back({0,num+1});
			num++;
			continue;
		}
		edges.push_back({num,num+1});
		num++;
	}
	while(num+1<n){
		edges.push_back({0,num+1});
		num++;
	}
	for(auto it : edges) cout<<it.first+1<<" "<<it.second+1<<"\n";
}