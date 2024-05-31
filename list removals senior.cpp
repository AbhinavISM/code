#include <bits/stdc++.h>
#define int long long
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, a, b) for (int i = a; i >= b; i--)
#define die(x) return cout << x << '\n', 0;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
void update(int idx, int val, int n, vector<int> &BIT){
  while(idx<=n){
    BIT[idx] += val;
    idx += ((idx)&(-idx));
  }
}
int query(int idx, vector<int> &BIT){
  int ans = 0;
  while(idx>0){
    ans += BIT[idx];
    idx -= ((idx)&(-idx));
  }
  return ans;
}
// void update(int x, int del, int n, vector<int> &bit) {
//   // queries are 1-based
//   while (x <= n) {
//     bit[x] += del;
//     x += x & (-x);
//   }
// }
// int query(int x, vector<int> &bit) {
//   int ans = 0;
//   while (x > 0) {
//     ans += bit[x];
//     x -= x & (-x);
//   }
//   return ans;
// }
 
int32_t main() {
    int n;
    cin >> n;
    int t = n;
    vector<int> vec(n+1,0);
    vector<int> bit(n+1,0);
    for(int i = 1; i<=n; i++){
      update(i, 1, n, bit);
      cin>>vec[i];
    }
    // vi vec(n + 1);
    // vi bit(n+1, 0);
    // rep(i, 1, n) {
    //   cin >> vec[i];
    //   update(i, 1, n, bit);
    // }
    while(t--) {
      int p;
      cin >> p;
      int lo = 1, hi = n, res;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (query(mid, bit) == p && vec[mid] != 0) {
          res = mid;
          break;
        } else if (query(mid, bit) >= p) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      cout << vec[res] << ' ';
      update(res, -1, n, bit);
      vec[res] = 0;
    } 
  return 0;
}