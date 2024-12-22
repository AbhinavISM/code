#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set

int32_t main(){
    fast_io;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int tn = n;
        if(n>60) tn = 60;
        if(k>(1ll<<(tn-1))){
            cout<<"-1"<<"\n";
            continue;
        }
        k--;
        vector<bool> binary(n-1, 0);
        int tk = k;
        for(int i = 0; i<n-1; i++){
            binary[i] = k%2;
            k/=2;
        }
        int cur = 1;
        vector<int> ans;
        set<int> s;
        for(int i = 1; i<=n; i++){
            s.insert(i);
        }
        for(int i = n-2; i>=0; i--){
            if(binary[i]) {
                ans.push_back(cur);
                s.erase(cur);
            }
            cur++;
        }
        reverse(ans.begin(), ans.end());
        vector<int> ans2;
        for(int i : s){
            ans2.push_back(i);
        }
        for(int i : ans){
            ans2.push_back(i);
        }
        peek(ans2)
    }
    return 0;
}