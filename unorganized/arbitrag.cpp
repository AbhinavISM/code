#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
    fast_io;
    int test = 0;
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        test++;
        map<string,int> nodeNames;
        for(int i=0; i<n; i++){
            string s;
            cin>>s;
            nodeNames[s]=i;
        }
        vector<vector<ld>> adj(n,vector<ld>(n,0.0));
        int m;
        cin>>m;
        for(int i = 0; i<m; i++){
            string curr1;
            string curr2;
            ld val;
            cin>>curr1>>val>>curr2;
            adj[nodeNames[curr1]][nodeNames[curr2]] = val;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){ 
                for(int j=0; j<n; j++){
                    adj[i][j] = max(adj[i][j], adj[i][k]*adj[k][j]);
                }
            }
        }
        bool flag = false;
        for(int i = 0 ; i < n ; i++){
                if(adj[i][i] > 1.0 ){
                    flag = true;
                    break;
                }
        }
        if(flag)
            cout<<"Case "<<test<<": Yes\n";
        else
            cout<<"Case "<<test<<": No\n";
    }
}