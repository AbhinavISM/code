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

bool cmp1(vector<int> &a, vector<int> &b){
	if(a[0]!=b[0]){
		return a[0]<b[0];
	} else {
		return a[1]>b[1];
	}
}
bool cmp2(vector<int> &a, vector<int> &b){
	if(a[1]!=b[1]){
		return a[1]>b[1];
	} else {
		return a[0]<b[0];
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> a(n);
		for(int i = 0; i<n; i++){
			int l,r;
			cin>>l>>r;
			a[i] = {l,r,i};
		}
		vector<vector<int>> ta = a;
		sort(a.begin(), a.end(), cmp1);
		// dpeek(a)
		set<int> end;
		end.insert(a[0][1]);
		vector<int> rans(n);
		rans[a[0][2]] = 0;
		for(int i = 1; i<n; i++){
			
			if(i<n-1 && a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1]){
				rans[a[i][2]] = (a[i][1]);
				end.insert(a[i][1]);
				continue;
			} else if(i>0 && a[i][0] == a[i-1][0] && a[i][1] == a[i-1][1]){
				rans[a[i][2]] = (a[i][1]);
				end.insert(a[i][1]);
				continue;
			}

			if(end.lower_bound(a[i][1])!=end.end()){
				int smallestr = *end.lower_bound(a[i][1]);
				rans[a[i][2]] = (smallestr);
			} else {
				rans[a[i][2]] = (0);
			}
			end.insert(a[i][1]);

		}
		// peek(rans)

		sort(a.begin(), a.end(), cmp2);
		// dpeek(a)
		set<int> start;
		start.insert(a[0][0]);
		vector<int> lans(n);
		lans[a[0][2]] = 0;
		for(int i = 1; i<n; i++){
			
			if(i<n-1 && a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1]){
				lans[a[i][2]] = (a[i][0]);
				start.insert(a[i][0]);
				continue;
			} else if(i>0 && a[i][0] == a[i-1][0] && a[i][1] == a[i-1][1]){
				lans[a[i][2]] = (a[i][0]);
				start.insert(a[i][0]);
				continue;
			}

			if(start.upper_bound(a[i][1])!=start.begin()){
				int largestl = *(--start.upper_bound(a[i][0]));
				lans[a[i][2]] = (largestl);
			} else {
				lans[a[i][2]] = (0);
			}
			start.insert(a[i][0]);

		}
		// peek(lans)

		vector<int> ans;
		for(int i = 0; i<n; i++){
			if(rans[i]!=0&&lans[i]!=0){
				ans.push_back((rans[i] - lans[i]) - (ta[i][1] - ta[i][0]));
			} else {
				ans.push_back(0);
			}
		}
		peek(ans)
	}
	return 0;
}