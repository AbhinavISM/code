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
		int n;
		cin>>n;
		int fz = -1;
		int zc = 0;
		vector<int> a(n,0);
		for(int i = 0; i<n; i++){
			cin>>a[i];
			if(a[i]==0) zc++;
			if(a[i]==0 && fz==-1) fz = i;
		}
		if(n==1 || zc==0) {
			cout<<n<<"\n";
			continue;
		}
		if(fz==0) {
			cout<<n-zc+1<<"\n";
			continue;
		}
		int mini = a[0];
		map<int, int> m;
		for(int i = 1; i<n; i++){
			if(a[i]!=0 || i==fz) m[a[i]]++;
		}
		int mex = 0;
		for(auto it : m){
			if(it.first==mex && it.second>0) mex++;
		}
		if(mini<mex){
			cout<<n-zc<<"\n";
			continue;
		}
		bool good = true;
		for(int i = 1; i<fz; i++){
			mini = min(mini, a[i]);
			m[a[i]]--;
			if(m[a[i]]==0 && mex>a[i]){
				mex = a[i];
				auto it = m.find(mex);
				while((*it).second==0){
					if(it==m.begin()) break;
					it--;
				}
				if(it==m.begin()){
					mex = 0;
				} else {
					mex = (*it).first + 1;
				}
			}
			if(mini<mex) good = false;
		}
		if(good){
			cout<<n-zc+1<<"\n";
		} else {
			cout<<n-zc<<"\n";
		}
	}
	return 0;
}