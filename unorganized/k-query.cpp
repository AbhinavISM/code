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
int n;
vector<int> a;
vector<vector<int>> seg;

vector<int> create(int num) {
 vector<int> temp;
 temp.push_back(num);
 return temp;
}
vector<int> combine(const vector<int>& a, const vector<int>& b) {
 int m = a.size(), n = b.size();
 int i = 0, j = 0;
 vector<int> c;

 while (i < m && j < n) {
   if (a[i] <= b[j]) {
     c.push_back(a[i]);
     i++;
   } else {
     c.push_back(b[j]);
     j++;
   }
 }

 while (i < m) {
   c.push_back(a[i]);
   i++;
 }

 while (j < n) {
   c.push_back(b[j]);
   j++;
 }
 return c;
}
void build(int node = 1, int l = 1, int r = n){
	if(l==r) {
		seg[node] = create(a[l]);
		return;
	}
	build(node*2, l, (l+r)/2);
	build(node*2+1, (l+r)/2+1, r);
	seg[node] = combine(seg[node*2], seg[node*2+1]);
}
int query(int x, int y, int k, int node = 1, int l = 1, int r = n){
	if (r < x || l > y) return 0;
	if (l >= x && r <= y) {
		int ans = seg[node].size() - (upper_bound(seg[node].begin(), seg[node].end(), k) - seg[node].begin());
		return ans;
	}
	int mid = (l + r) / 2;
	int a1 = query(x, y, k, node * 2, l, mid);
	int a2 = query(x, y, k, node * 2 + 1, mid+1, r);
	return a1+a2;
}
int32_t main(){
	fast_io;
	cin>>n;
	a.resize(n+1);
	seg.resize(4*n+2);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	build();
	int q; cin>>q;
	while(q--){
		int i,j,k;
		cin>>i>>j>>k;
		cout<<query(i,j,k)<<"\n";
	}
}