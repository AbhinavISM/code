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

long getMinCost(int edgeDeviceCost, int inputPeripheralCost, int bundleCost, int x, int y){
    int e = edgeDeviceCost; int i = inputPeripheralCost; int b = bundleCost;
    long ans = 0;
    if(e + i >= b){
        int bb = min(x ,y);
        ans += b*bb;
        x -= bb;
        y -= bb;
    }
    if(x>0){
        int cost = min(e, b);
        ans += cost*x;
    }
    if(y>0){
        int cost = min(i, b);
        ans += cost*y;
    }
    return ans;
}
int32_t main(){
    fast_io;
    cout<<getMinCost(3,2,1,4,3);
    return 0;
}