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

int lower_bound(vector<int> &a, int x, int n){
    int lo = 0;
    int hi = n-1;
    int ans = n;
    while(hi>=lo){
        int mid = lo + (hi-lo)/2;
        if(a[mid]>=x){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
int32_t main(){
    fast_io;
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    while(k--){
        int x;
        cin>>x;
        cout<<lower_bound(a, x, n)+1<<"\n";
    }
    return 0;
}