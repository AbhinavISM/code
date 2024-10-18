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

void findgoodmasks(int i, int k, int mask, int n, vector<int> &goodmasks){
	if(i==n&&k>=0) {
		goodmasks.push_back(mask);
		return;
	}
	if(k<0) return;
	findgoodmasks(i+1,k,mask,n,goodmasks);
	findgoodmasks(i+1,k-1,mask|(1<<i),n,goodmasks);
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b;
		vector<int> af(26,0);
		for(int i = 0; i<n; i++){
			af[a[i]-'a']++;
		}
		vector<int> aunique;
		for(int i=0; i<26; i++){
			if(af[i]) aunique.push_back(i);
		}
		int ans = 0;
		vector<int> goodmasks;
		findgoodmasks(0,k,0,aunique.size(), goodmasks);
		for(int mask : goodmasks){
			vector<bool> canReplace(26,false);
			int canReplaceCnt = 0;
			for(int i = 0; i<aunique.size(); i++){
				if(mask&(1<<i)) {
					canReplace[aunique[i]] = true;
					canReplaceCnt++;
				}
			}
			if(canReplaceCnt<=k){
				int tans = 0;
				int start = 0;
				int end = -1;
				for(int i = 0; i<n; i++){
					if(a[i]!=b[i]){
						if(canReplace[a[i]-'a']) {
							end++;
						}
						else {
							int len = end - start + 1;
							tans += (len*(len+1))/2;
							start = i+1;
							end = i;
						}
					} else {
						end++;
					}
				}
				int len = end - start + 1;
				tans += (len*(len+1))/2;
				ans = max(ans, tans);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}