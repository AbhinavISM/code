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

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i : arr )cin>>i;

    vector<int> pos;
	vector<int> neg;
    for(int i = 0; i<n; i++){
    	if(arr[i]>=0) pos.push_back(arr[i]);
    	else neg.push_back(arr[i]);
    }

    vector<int> dumb = arr;
    sort(dumb.begin(), dumb.end());
    int dif = dumb[n-1] - dumb[0];
    
    int i=0,j=0;
    int net = 0;
    vector<int> ans;
    while(i<neg.size()&&j<pos.size()){
        if(net>=0){
            ans.push_back(neg[i]);
            net+=neg[i++];
        }
        else{
            ans.push_back(pos[j]);
            net+=pos[j++];
        }
        if(abs(net)>=dif){
            cout<<"No"<<endl;
            return;
        }
    }
    while(i<neg.size()){
        ans.push_back(neg[i]);
        net+=neg[i++];
        if(abs(net)>=dif){
            cout<<"No"<<endl;
            return;
        }
    }
    while(j<pos.size()){
        ans.push_back(pos[j]);
        net+=pos[j++];
        if(abs(net)>=dif){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes\n";
    for(auto i : ans )cout<<i<<" ";
        cout<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}