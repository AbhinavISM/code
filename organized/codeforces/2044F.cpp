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
bool check(set<int> &sa, set<int> &sb, int suma, int sumb, int d1, int d2){
	if(sa.find(suma-d1)!=sa.end() && sb.find(sumb-d2)!=sb.end()){
		return true;
	} else if(sa.find(suma-d2)!=sa.end() && sb.find(sumb-d1)!=sb.end()){
		return true;
	}
	return false;
}
int32_t main(){
	fast_io;
	int n,m,q;
	cin>>n>>m>>q;
	vector<int> a(n,0);
	set<int> sa;
	int suma = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		sa.insert(a[i]);
		suma+=a[i];
	}
	vector<int> b(m,0);
	set<int> sb;
	int sumb = 0;
	for(int i = 0; i<m; i++){
		cin>>b[i];
		sb.insert(b[i]);
		sumb+=b[i];
	}
	set<int> allpossible;
	for(int i = 1; i<=200000; i++){
		for(int j = 1; j<=200000; j++){
			if(i*j>200000) break;
			if(check(sa,sb,suma,sumb,i,j) || check(sa,sb,suma,sumb,-i,-j)){
				allpossible.insert(i*j);
			}
			if(check(sa,sb,suma,sumb,-i,j) || check(sa,sb,suma,sumb,i,-j)){
				allpossible.insert(-1*i*j);
			}
		}
	}
	while(q--){
		int x;
		cin>>x;
		if(allpossible.find(x)!=allpossible.end()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}