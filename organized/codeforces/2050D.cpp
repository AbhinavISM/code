#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;cout<<"\n";
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
		string s;
		cin>>s;
		int n = s.length();
		set<pair<int, int>> st;
		for(int i = 0; i<n; i++){
			st.insert({i, s[i]-'0'});
		}
		vector<int> ans(n);
		for(int i=0; i<n; i++){
			auto it = st.begin();
			int maxi = (*it).second;
			for(int j = 1; j<=9; j++){
				it++;
				if(it==st.end()) break;
				maxi = max(maxi, (*it).second - j);
			}
			// cout<<maxi<<"\n";
			it = st.begin();
			if(maxi==(*it).second){
				ans[i] = maxi;
				st.erase(it);
			} else {
				for(int j = 1; j<=9; j++){
					it++;
					if(it==st.end()) break;
					if(maxi==(*it).second-j){						
						ans[i] = maxi;
						st.erase(it);
						break;
					}
				}
			}
		}
		peek(ans)
	}
	return 0;
}