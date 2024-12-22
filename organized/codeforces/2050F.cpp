#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set

class Seg {
	public:
	int gcd(int a,int b){
    	if(a == 0) return b;
		return gcd(b%a, a);
	}
	int n;
	vector<int> a;
	vector<int> seg;
	Seg(int n1, vector<int> a1, vector<int> seg1){
		n = n1; a = a1; seg = seg1;
	}
	int rangeMin(int x, int y, int node, int l, int r){
		if(l>=x&&r<=y) return seg[node];
		if(l>y||r<x) return 0;
		return gcd(rangeMin(x,y,node*2,l,(l+r)/2), rangeMin(x,y,node*2+1,(l+r)/2+1,r));
	}
	void build(int node, int l, int r){
		if(l==r) {
			seg[node] = a[l];
			return;
		}
		int mid = (l+r)/2;
		build(node*2, l, mid);
		build(node*2+1, mid+1, r);
		seg[node] = gcd(seg[node*2], seg[node*2+1]);
	}
};

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		vector<int> a(n+1, 0);
		for(int i = 1; i<=n; i++){
			cin>>a[i];
		}
		vector<int> b(n, 0);
		for(int i = 1; i<n; i++){
			b[i] = abs(a[i] - a[i+1]);
		}
		vector<int> sarr(4*n+2);
		Seg seg = Seg(n, b, sarr);
		if(n!=1) seg.build(1, 1, n);
		// peek(b);
		for(int i = 0; i<q; i++){
			int l, r;
			cin>>l>>r;
			if(n==1||r==l) cout<<0<<" ";
			else if(r>=l+1) cout<<seg.rangeMin(l, r-1, 1, 1, n)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

