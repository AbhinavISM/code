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
	vector<vector<int>> graph(n,vector<int>());
	for(int i = 0; i<n-1; i++){
		int a;
		cin>>a;
		graph[a-1].push_back(i+1);
	}
	queue<int> q;
	vector<int> dis(n,INT_MAX);
	int src = 0;
	q.push(src); dis[src] = 0;
	while(!q.empty()){
	    int node = q.front();
	    q.pop();
	    for(int child : graph[node]){
	        if(dis[child]==INT_MAX){
	            dis[child] = dis[node] + 1;
	            q.push(child);
	        }
	    }
	}
	bool good = true;
	for(auto nbr : graph){
		if(nbr.size()>0){
			int leaf = 0;
			for(int child : nbr){
				if(graph[child].size()==0) leaf++;
			}
			if(leaf<3){
				good = false;
			}
		}
	}
	if(good){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}