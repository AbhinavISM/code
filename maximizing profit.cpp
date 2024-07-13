#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> vp;
  for (ll i = 0; i < n; i++)
  {
    ll c, d;
    cin >> c >> d;
    vp.push_back({d, c});
  }
  sort(vp.begin(), vp.end());
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll ans = 0;
  ll sum = 0;
  for (ll i = n - 1; i >= 0; i--)
  {
    if ((ll)pq.size() < m)
    {
      pq.push(vp[i].second);
      sum += vp[i].second;
    }
    else
    {
      auto it = pq.top();
      if (it < vp[i].second)
      {
        pq.pop();
        sum -= it;
        pq.push(vp[i].second);
        sum += vp[i].second;
      }
    }
    if ((ll)pq.size() == m){
      ans = max(ans, sum + m * vp[i].first);
    }
  }
  cout<<ans<<endl;
}
int main(){
  fast_io;
  ll t;
  cin>>t;
  while(t--){
    solve();
}
  return 0;
}