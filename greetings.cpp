#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i].first>> arr[i].second;
    sort(arr.begin(),arr.end());
    ordered_set st;
    for(auto i: arr){
        st.insert(i.second);
    }
    int ans = 0;
    for(auto i: arr){
        ans = ans+st.order_of_key(i.second);
        st.erase(st.find(i.second));
    }
    cout<<ans<<endl;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	//way 2 (MAST)
	solve();
	
	//way 1 (BEKAAR)
	// int n;
	// cin>>n;
	// vector<int> a(n);
	// vector<int> b(n);
	// map<int,int> m;
	// for(int i = 0; i<n; i++){
	// 	cin>>a[i]>>b[i];
	// 	m[b[i]]=a[i];
	// }
	// sort(a.begin(), a.end());
	// sort(b.begin(), b.end(), greater<int>());
	// ordered_set already;
	// int ans = 0;
	// for(int e : b){
	// 	auto ub = upper_bound(a.begin(), a.end(), m[e]);
	// 	int cnt;
	// 	if(ub==a.end()){
	// 		cnt = 0;
	// 	} else {
	// 		cnt = (a.end()-ub);	
	// 	}
	// 	cnt-=(already.size()-already.order_of_key(m[e])); //order_of_key(x) gives number of elements smaller than x in the set
	// 	ans+=cnt;
	// 	already.insert(m[e]);
	// }
	// cout<<ans<<"\n";
}
	return 0;
}