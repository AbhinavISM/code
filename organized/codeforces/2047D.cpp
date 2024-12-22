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

void rec(multiset<pair<int, int>> &s, multiset<pair<int, int>> &s1, int mini, int minidx, vector<int> &ans, vector<int> &a){
	if(s.size()==0){
		for(auto it : s1){
				ans.push_back(it.first + 1);
			}
		return;
	}
	int m1 = (*s1.begin()).first;
	int m = (*s.begin()).first;
	if(m1+1<m){
		ans.push_back(m1+1);
		s1.erase(s1.begin());
		for(auto it : s){
			s1.insert(it);
		}
		for(auto it : s1){
			ans.push_back(it.first + 1);
		}
		return;
	} else {
		int thisidx = (*s.begin()).second;
		ans.push_back(m);
		s.erase(s.begin());
		for(int i = minidx+1; i<thisidx; i++){
			s.erase(s.find({a[i], i}));
			s1.insert({a[i], i});
		}
		rec(s, s1, m, thisidx, ans, a);
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0);
		int mini = INT_MAX;
		int minidx;
		for(int i = 0; i<n; i++){
			cin>>a[i];
			if(a[i]<mini){
				mini = a[i];
				minidx = i;
			}
		}
		vector<int> ans;
		ans.push_back(mini);
		multiset<pair<int, int>> s1;		
		multiset<pair<int, int>> s;
		for(int i = 0; i<n; i++){
			if(i<minidx){
				s1.insert({a[i], i});
			} else if(i>minidx){
				s.insert({a[i], i});
			}
		}
		rec(s, s1, mini, minidx, ans, a);
		peek(ans)
	}
	return 0;
}