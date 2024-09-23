#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 1 && x <= r && y >= 1 && y <= c)
using namespace std;
int32_t main(){
    fast_io;
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+2, vector<int>(m+2,0));
    for(int i = 1; i<=n; i++){
        string s;
        cin>>s;
        for(int j = 1; j<=m; j++){
            a[i][j] = (int)(s[j-1] - 48);
        }
    }
    deque<pair<int,int>> q;
    vector<vector<int>> distance(n+2,vector<int>(m+2,INT64_MAX));
    for(int i = 0; i<=n+1; i++){
        for(int j = 0; j<=m+1; j++){
            if(i==0||j==0||i==n+1||j==m+1) {
                q.push_back({i,j});
                distance[i][j] = 0;
            }
        }
    }
    while(q.size()!=0){
        int i = q.front().first;
        int j = q.front().second;
        q.pop_front();
        int c[] = {0, -1, 0, 1};
        int b[] = {-1, 0, 1, 0};
        for(int x=0;x<4;x++){
            int tmpX = i + c[x];
            int tmpY = j + b[x];
            if(in_range(tmpX, tmpY, n, m)){
                if((a[tmpX][tmpY]==0)&&distance[tmpX][tmpY]>distance[i][j]){
                    distance[tmpX][tmpY] = distance[i][j];
                    q.push_front({tmpX, tmpY});
                } else if(distance[tmpX][tmpY]>distance[i][j] + 1){
                    distance[tmpX][tmpY] = distance[i][j] + 1;
                    q.push_back({tmpX,tmpY});
                }
            }
        }
    }
    // dpeek(a)
    // dpeek(distance)
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i][j]==0) ans = max(ans, distance[i][j]);
        }
    }
    cout<<ans<<"\n";
}
    return 0;
}