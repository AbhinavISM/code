#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define ff first
#define ss second
using namespace std;
int n,q;
vector<int> a;
vector<pii> seg;

pii combine(pii &p1, pii&p2){
	pii ans;
	if(p1.ff==p2.ff){
		ans = p1;
		ans.ss += p2.ss;
	} else if(p1.ff>p2.ff){
		ans = p2;
	} else {
		ans = p1;
	}
	return ans;
}
void build(int node = 1, int l = 1, int r = n){
	if(l==r) {
		seg[node] = {a[l], 1};
		return;
	}
	int mid = l + (r-l)/2;
	build(node*2, l, mid);
	build(node*2+1, mid+1, r);
	int c1 = node*2;
	int c2 = node*2 + 1;
	seg[node] = combine(seg[c1], seg[c2]);
}
void update(int pos, int val, int node = 1, int l = 1, int r = n){
	if(l==r){
		seg[node] = {val,1};
		a[pos] = val;
		return;
	}
	int c1 = node*2;
	int c2 = node*2 + 1;
	int mid = l + (r-l)/2;
	if(pos<=mid) update(pos, val, c1, l, mid);
	else update(pos, val, c2, mid+1, r);
	seg[node] = combine(seg[c1], seg[c2]);
}
pii rangeMin(int x, int y, int node = 1, int l = 1, int r = n){
	if(l>=x&&r<=y) return seg[node];
	else if(x>r||y<l) return {INT_MAX,0};
	else {
		pii a1 = rangeMin(x, y, node*2, l, (l+r)/2);
		pii a2 = rangeMin(x, y, node*2+1, (l+r)/2+1, r);
		return combine(a1, a2);
	}
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
	while(q--){
		int type, x, y;
		cin>>type>>x>>y;
		if(type==1) update(x+1,y);
		else cout<<rangeMin(x+1,y).ff<<" "<<rangeMin(x+1,y).ss<<"\n";
	}
}