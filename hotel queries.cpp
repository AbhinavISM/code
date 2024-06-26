#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
#define ff first
#define ss second
using namespace std;
int n; int m;
vector<int> a;
vector<int> r;
vector<int> seg;
void build(int node = 1, int l = 1, int r = n){
	if(l==r) {
		seg[node] = a[l];
		return;
	}
	build(node*2, l, (l+r)/2);
	build(node*2+1, (l+r)/2+1, r);
	seg[node] = max(seg[node*2], seg[node*2+1]);
}
void update(int pos, int val, int node = 1, int l = 1, int r = n){
	if(l==r){
		a[l] = val;
		seg[node] = val;
		return;
	}
	int mid = l + (r-l)/2;
	if(pos<=mid) update(pos, val, node*2, l, mid);
	else update(pos, val, node*2+1, mid+1, r);
	seg[node] = max(seg[node*2], seg[node*2+1]);
}
int query(int need, int node = 1, int l = 1, int r = n){
	// cout<<l<<" "<<r<<"\n";
	if(seg[node]<need) return 0;
	else if(l==r) return l;
	else if(seg[node*2]>=need) return query(need, node*2, l, (l+r)/2);
	else if(seg[node*2+1]>=need) return query(need, node*2+1, (l+r)/2+1, r);
}
int32_t main(){
	fast_io;
	cin>>n>>m;
	a.resize(n+1);
	seg.resize(4*n+2);
	r.resize(m);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	for(int i = 0; i<m; i++){
		cin>>r[i];
	}
	build();
	for(int i = 0; i<m; i++){
		int hnum = query(r[i]);
		if(hnum>0) update(hnum, a[hnum] - r[i]);
		cout<<hnum<<" ";
	}
}