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
		string s;
		cin>>s;
		vector<int> a;
		for(int i = 0; i<n; i++){
			if(s[i]=='0') a.push_back(0);
			else a.push_back(1);	
		}
		vector<int> f;
		int ones = 0;
		int zeroes = 0;
		for(int i = n-1; i>=1; i--){
			if(a[i]) {
				ones++;
			} else {
				zeroes++;
			}
			f.push_back(ones - zeroes);
		}
		sort(f.begin(), f.end(), greater<int>());
		int ans = 1;
		int score = 0;
		for(int i = 0; i<f.size(); i++){
			score += f[i];
			ans++;
			if(score>=k) break;
		}
		if(score<k) cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}