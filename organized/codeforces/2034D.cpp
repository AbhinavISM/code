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
		vector<int> a(n,0);
		vector<int> f(3, 0);
		for(int i = 0; i<n; i++){
			cin>>a[i];
			f[a[i]]++;
		}
		set<int> badzeroes;
		set<int> badtwos;
		set<int> onesonzeroes;
		set<int> onesontwos;
		for(int i = 0; i<f[0]; i++){
			if(a[i]==1){
				onesonzeroes.insert(i);
			} else if(a[i]==2){
				badtwos.insert(i);
			}
		}
		for(int i = f[0]; i<f[0]+f[1]; i++){
			if(a[i]==0){
				badzeroes.insert(i);
			} else if(a[i]==2){
				badtwos.insert(i);
			}
		}
		for(int i = f[0]+f[1]; i<f[0]+f[1]+f[2]; i++){
			if(a[i]==1){
				onesontwos.insert(i);
			} else if(a[i]==0){
				badzeroes.insert(i);
			}
		}
		// peek(badzeroes)
		// peek(badtwos)
		// peek(onesonzeroes)
		// peek(onesontwos)
		int ans = 0;
		vector<vector<int>> fans;
		while(badzeroes.size()>0 || badtwos.size()>0){
			if(!onesonzeroes.empty()){

				int onepos = *onesonzeroes.begin();
				int zeropos = *badzeroes.begin();
				badzeroes.erase(zeropos);
				onesonzeroes.erase(onepos);
				
				ans++;
				fans.push_back({onepos+1, zeropos+1});
				swap(a[onepos], a[zeropos]);
				swap(onepos, zeropos);

				if(onepos>=f[0]+f[1]) {
					onesontwos.insert(onepos);
				}
			} else if(!onesontwos.empty()){
				int onepos = *onesontwos.begin();
				int twopos = *badtwos.begin();
				badtwos.erase(twopos);
				onesontwos.erase(onepos);
				
				ans++;
				fans.push_back({onepos+1, twopos+1});
				swap(a[onepos], a[twopos]);
				swap(onepos, twopos);

				if(onepos<f[0]) {
					onesonzeroes.insert(onepos);
				}
			} else {
				break;
			}
		}
		int onepos = f[0] + f[1] - 1;
		while(badzeroes.size()>0&&badtwos.size()>0){
			int zeropos = *badzeroes.begin();
			int twopos = *badtwos.begin();
			badtwos.erase(twopos);
			badzeroes.erase(zeropos);

			ans++;
			fans.push_back({twopos+1, onepos+1});
			swap(a[twopos], a[onepos]);
			swap(twopos, onepos);

			ans++;
			fans.push_back({onepos+1, zeropos+1});
			swap(a[onepos], a[zeropos]);
			swap(onepos, zeropos);

			if(badzeroes.size()==0){
				ans++;
				fans.push_back({f[0] + f[1], onepos+1});
				swap(a[f[0]+f[1]-1], a[onepos]);
			}
		}
		cout<<ans<<"\n";
		dpeek(fans)
	}
	return 0;
}