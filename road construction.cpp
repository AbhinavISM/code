#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
vector<int> par(100001);
vector<int> rnk(100001);
void make_set(int n){
	for(int i = 0; i<=n; i++){
		par[i] = i;
		rnk[i] = 1;
	}
}
int find_set(int a){
	if(par[a]==a){
		return a;
	}
	par[a] = find_set(par[a]);
	return par[a];
}

void union_set(int a, int b){
	int p1 = find_set(a);
	int p2 = find_set(b);
	if(p1==p2){
		return;
	}
	if(rnk[p1]>=rnk[p2]){
		par[p2] = p1;
		rnk[p1] += rnk[p2];
	} else {
		par[p1] = p2;
		rnk[p2] += rnk[p1];
	}
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	make_set(n);
	int num = n;
	int largest = 1;
	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		int pu = find_set(u);
		int pv = find_set(v);
		if(pu!=pv){
			union_set(pu,pv);
			num -= 1;
			largest = max(largest, max(rnk[pu], rnk[pv]));
		}
		cout<<num<<" "<<largest<<"\n";
	}
}