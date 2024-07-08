#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, seg, lazy;
int n, m;

void build(int id = 1, int l = 1, int r = n) {
  if (r==l) {
    seg[id] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid+1, r);
  seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
// Time complexity: O(n)

const int inf = 1e18;
//CODE IS NOT ACCEPTED YET
int query(int x, int y, int id = 1, int l = 1, int r = n) {
  if (l > y || r < x) return inf;
  if (l >= x && r <= y) {
    seg[id] += lazy[id];
    if(id*2<=4*n) lazy[id*2] += lazy[id];
    if(id*2+1<=4*n) lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    return seg[id];
  }
  seg[id] += lazy[id];
  if(id*2<=4*n) lazy[id*2] += lazy[id];
  if(id*2+1<=4*n) lazy[id*2+1] += lazy[id];
  lazy[id] = 0;
  int mid = (l + r) / 2;
  int l_ans = query(x, y, id * 2, l, mid);
  int r_ans = query(x, y, id * 2 + 1, mid+1, r);
  return min(l_ans, r_ans);
}
// Time complexity: O( log(N) )



void increase(int x, int y, int val, int id = 1, int l = 1, int r = n) {
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    seg[id] += lazy[id];
    seg[id] += val;
    lazy[id] += val;
    if(id*2<=4*n) lazy[id*2] += lazy[id];
    if(id*2+1<=4*n) lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    return;
  }
  seg[id] += lazy[id];
  if(id*2<=4*n) lazy[id*2] += lazy[id];
  if(id*2+1<=4*n) lazy[id*2+1] += lazy[id];
  lazy[id] = 0;
  int mid = (l + r) / 2;
  increase(x, y, val, id * 2, l, mid);
  increase(x, y, val, id * 2 + 1, mid+1, r);
  seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
// Time complexity: O( log(N) )

int32_t main() {
  cin >> n >> m;

  a = vector<int>(n+1,0);
  seg = vector<int>(4*n+2,0);
  lazy = vector<int>(4*n+2,0);

  build();

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y, val;
      cin >> x >> y >> val;
      increase(x, y-1, val);
    } else {
      int x, y;
      cin >> x >> y;
      cout << query(x, y-1) << '\n';
    }
  }

  return 0;
}
