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
		string s;
		cin>>s;
		int c2 = 0;
		int c6 = 0;
		int sum = 0;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='2') c2++;
			else if(s[i]=='3') c6++;
			sum += (s[i] - '0');
		}
		int need = ((sum+8)/9)*9 - sum;
		set<int> s1;
		set<int> s2;
		for(int i = 0; i<=c2; i++){
			s1.insert(2*i % 9);
		}
		for(int i = 0; i<=c6; i++){
			s2.insert(6*i % 9);
		}
		set<int> f;
		for(int i : s1){
			f.insert(i);
			for(int j : s2){
				f.insert(j);
				f.insert((i+j)%9);
			}
		}
		if(f.find(need)!=f.end()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}