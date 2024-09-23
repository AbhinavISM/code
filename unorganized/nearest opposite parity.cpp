#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(int x:v) cout<<(x!=INT_MAX?x:-1)<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t=1;
	while(t--){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i = 1; i<=n; i++){
		if(i-a[i]>=1) adj[i-a[i]].push_back(i);
		if(i+a[i]<=n) adj[i+a[i]].push_back(i);
	}
	queue<int> q1;
	vector<int> dis1(n+1,INT_MAX);
	queue<int> q2;
	vector<int> dis2(n+1,INT_MAX);
	for(int i = 1; i<=n; i++){
		if(a[i]%2){
			q1.push(i);
			dis1[i] = 0;
		} else {
			q2.push(i);
			dis2[i] = 0;
		}
	}
	while(!q1.empty()){
		int node = q1.front();
		q1.pop();
		for(int child : adj[node]){
			if(dis1[child]==INT_MAX){
				dis1[child] = dis1[node] + 1;
				q1.push(child);
			}
		}
	}
	while(!q2.empty()){
		int node = q2.front();
		q2.pop();
		for(int child : adj[node]){
			if(dis2[child]==INT_MAX){
				dis2[child] = dis2[node] + 1;
				q2.push(child);
			}
		}
	}
	vector<int> ans(n);
	for(int i = 1; i<=n; i++){
		if(a[i]%2){
			ans[i-1] = dis2[i];
		} else {
			ans[i-1] = dis1[i];
		}
	}
	peek(ans)
}
	return 0;
}