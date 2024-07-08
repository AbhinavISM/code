#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
#define ll long long
class Node{
    int f;
    vector<pii> cost;
    vector<Node*> children;
    Node(){
        f = 0;
        cost=  vector<pii>();
        children = vector<Node*>(26, NULL);
    }
};
class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
    }
};

int main(){
    fast_io;
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vector<ll> a(n,0);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
    }
}
    return 0;
}