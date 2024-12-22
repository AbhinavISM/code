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
set<pair<int, int>> mergeOverlap(set<pair<int, int>>& arr) {
    set<pair<int, int>> res;
    res.insert(*arr.begin());
    for (auto it : arr) {
        auto last = *(--res.end());
        if(it.first<=last.second){
        	int newl = last.first;
        	int newr = max(last.second, it.second);
        	res.erase(last);
        	res.insert({newl, newr});
        } else {
        	res.insert(it);
        }
    }
    return res;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,m,q;
		cin>>n>>m>>q;
		vector<int> queries(q,0);
		for(int i = 0; i<q; i++){
			cin>>queries[i];
		}
		set<pair<int, int>> s;
		s.insert({m,m});
		for(int i = 0; i<q; i++){
			set<pair<int, int>> st;
			for(auto it : s){
				int l = it.first;
				int r = it.second;
				if(queries[i]<l) {
					l--;
					st.insert({l,r});
				} else if(queries[i]>r){
					r++;
					st.insert({l,r});
				} else if(l==r){
					st.insert({1,1});
					st.insert({n,n});
				} else {
					if(l<=2&&r>=n-1){
						l = 1;
						r = n;
						st.insert({l,r});
					} else if(l<=2){
						l = 1;
						st.insert({l,r});
						st.insert({n,n});
					} else if(r>=n-1){
						r = n;
						st.insert({l,r});
						st.insert({1,1});
					} else {
						st.insert({l,r});
						st.insert({1,1});
						st.insert({n,n});
					}
				}
			}
			st = mergeOverlap(st);
			s = st;
			int ans = 0;
			for(auto it : s){
				ans += (it.second - it.first + 1);
			}
			cout<<ans;
			cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}