#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int n,q;
vector<int> a;
vector<int> seg;
void update(int pos, int val, int node = 1, int l = 1, int r = n){
	if(l==r) {
		a[pos] = val;
		seg[node] = val;
		return;
	}
	int mid = (l+r)/2;
	if(pos<=mid) update(pos, val, node*2, l, mid);
	else update(pos, val, node*2+1, mid+1, r);
	seg[node] = min(seg[node*2], seg[node*2+1]);
}
int rangeMin(int x, int y, int node = 1, int l = 1, int r = n){
	//entirely inside the desired range
	if(l>=x&&r<=y) return seg[node];
	//entirely outside the desired range
	if(l>y||r<x) return INT_MAX;
	//partially inside the desired range
	return min(rangeMin(x,y,node*2,l,(l+r)/2), rangeMin(x,y,node*2+1,(l+r)/2+1,r));
}
void build(int node = 1, int l = 1, int r = n){
	if(l==r) {
		seg[node] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(node*2, l, mid);
	build(node*2+1, mid+1, r);
	seg[node] = min(seg[node*2], seg[node*2+1]);
}
int32_t main(){
	fast_io;
	cin>>n>>q;
	a.resize(n+1);
	seg.resize(4*n+2);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	build();
	peek(seg)
	while(q--){
		int type, x, y;
		cin>>type>>x>>y;
		if(type==1) update(x,y);
		else cout<<rangeMin(x,y)<<"\n";
	}
}