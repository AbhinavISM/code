#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
vector<int> masses;
vector<int> dp;
int solve(int x){
    if(x==0){
        return 0;
    }
    
    if(dp[x]!=-1) return dp[x];
    int ans=0;
    for(int i=0;i<4;i++){
        if(x>=masses[i]){
            ans=max(ans,solve(x-masses[i])+1);
        }
    }
    return dp[x]=ans;
}
int32_t main(){
    fast_io;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    c*=2;
    d*=2;
    int x;
    cin>>x;
    masses.push_back(a);
    masses.push_back(b);
    masses.push_back(c);
    masses.push_back(d);
    dp.resize(x+1,-1);
    cout<<solve(x);
    return 0;
}