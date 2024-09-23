#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<ll> i : v) {for(ll j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

ll fn(vector<ll> a,vector<ll> b,ll n){
  vector<vector<ll>> dp(2, vector<ll>(n,1e9));
  dp[0][0] = a[0];
  for (ll i = 0; i < 2;i++){
    for (ll j = 0; j < n;j++){
      if(i-1>=0)
      	if(i==0)
        	dp[i][j] = min(dp[i][j], max(a[j], dp[i-1][j]));
    	else
        	dp[i][j] = min(dp[i][j], max(b[j], dp[i-1][j]));
      if(j-1>=0)
      	if(i==0)
        	dp[i][j] = min(dp[i][j], max(a[j], dp[i][j-1]));
    	else
        	dp[i][j] = min(dp[i][j], max(b[j], dp[i][j-1]));
    }
  }
  return dp[1][n - 1];
}

string solution(string &forth){
    int xmin = 0 , xmax = 0;
    int x = 0 , y = 0;
    for(char d : forth){
        if(d == 'E') xmax = max(xmax , ++x);
        else if(d == 'W') xmin = min(xmin , --x);
        else y++;
    }
    string L = string(x + 1 - xmin , 'W') + string(y , 'S') + string(1 - xmin , 'E');
    string R = string(xmax + 1 - x , 'E') + string(y , 'S') + string(xmax + 1, 'W');
    return L.size() < R.size() ? L:R;
}//MS 1

string func(string s){
    vector<pair<ll,ll>> v1;
    ll x=0,y=0;
    ll minX=0,maxX=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='N') y++;
        else if(s[i]=='S') y--;
        else if(s[i]=='E') x++;
        else x--;
        minX=min(minX,x);
        maxX=max(maxX,x);
    }

    ll temp1=x-2*(minX-1);
    ll temp2=2*(maxX+1)-x;
    string ans;
    if(temp1<temp2){
        ll p1=x-(minX-1),q1=-(minX-1);
        for(int i=0;i<p1;i++) ans.push_back('W');
        for(int i=0;i<y;i++) ans.push_back('S');
        for(int i=0;i<q1;i++) ans.push_back('E');
    }else{
        ll p1=(maxX+1)-x,q1=(maxX+1);
        for(int i=0;i<p1;i++) ans.push_back('E');
        for(int i=0;i<y;i++) ans.push_back('S');
        for(int i=0;i<q1;i++) ans.push_back('W');
    }

    return ans;
}

// //MS 3
int main(){
	fast_io;
	// ll n;
	// cin>>n;
	// vector<ll> a(n,0);
	// for(ll i = 0; i<n; i++){
	// 	cin>>a[i];
	// }
	// vector<ll> b(n,0);
	// for(ll i = 0; i<n; i++){
	// 	cin>>b[i];
	// }
	// cout<<fn(a,b,n);
	string s;
	cin>>s;
	cout<<func(s)<<" "<<solution(s);
	return 0;
}

// void dfs(vector<vector<int>> & adj,vector<int> &vis,int node,vector<int>&par){
//     vis[node] = 1;
    
//     for(auto i:adj[node]){
//         if(vis[i] == -1){
//             par[i] = node;
//             dfs(adj,vis,i,par);
//         }
//     }
// }
// int solve(vector<int> A,vector<int> B){
//     int n;
//     n = A.size()+1;
//     // for(auto i:A)cout<<i<<" ";
//     vector<vector<int>> adj(n);
//     set<pair<int,int>> st;
//     for(int i=0;i<A.size();i++){
//         adj[B[i]].push_back(A[i]);
//         adj[A[i]].push_back(B[i]);
//         st.insert({A[i],B[i]});
//     }
//     vector<int> vis(n,-1),par(n,-1);
//     dfs(adj,vis,0,par);
//     int ans = 0;
//     for(int i=1;i<n;i++ ){
//         pair<int,int> p = {i,par[i]};
//         if(st.find(p) == st.end()){
//             ans++;
//         }
//     }
//     return ans;
// }