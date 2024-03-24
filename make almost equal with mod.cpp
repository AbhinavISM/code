#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define range 200001
#define check cout<<"This worked\n";
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
int32_t main(){
    fastio
    int t;
    cin>>t;
    while(t--) {
        int n ;
        cin>>n ;
        vector<int> a(n+1) ;
        for(int i=1;i<=n;i++) cin>>a[i] ;
        int ans ;
        for(int i=0;i<=62;i++) {
            int m = (1ll<<i) ;
            map<int,int> f ; 
            for(int j=1;j<=n;j++) {
                f[a[j]%m]++;
            }
            if(f.size()==2) {
                ans = m ;
                break ;
            }
        }
        cout<<ans<<"\n";
    }
    
}