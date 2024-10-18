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
		vector<int> a(n);
		for(int i = 0; i<n; i++){
			cin>>a[i];	
		}
		int i = 0;
		int j = 0;
		int maxi = 0;
		int lans = n;
		int rans = 0;
		while(i<n){
			vector<int> f(5,0);
			while(i<n&&a[i]!=0){
				f[a[i]+2]++;
				i++;
			}
			int negcnt = f[0]+f[1];
			if(negcnt%2){
				vector<int> tf = f;
				int k = j;
				for(; k<i; k++){
					tf[a[k]+2]--;
					if(a[k]<0) break;
				}
				if(k<i){
					if((tf[0]+tf[4])>maxi){
						maxi = tf[0]+tf[4];
						lans = k+1;
						rans = n-i;
					}
				}

				tf = f;
				k = i-1;
				for(; k>=j; k--){
					tf[a[k]+2]--;
					if(a[k]<0) break;
				}
				if(k>=j){
					if((tf[0]+tf[4])>maxi){
						maxi = tf[0]+tf[4];
						lans = j;
						rans = n-k;
					}
				}
			} else {
				if((f[0]+f[4])>maxi){
					maxi = (f[0]+f[4]);
					lans = j;
					rans = n-i;
				}
			}
			i++;
			j=i;
		}
		cout<<lans<<" "<<rans<<"\n";
	}
	return 0;
}