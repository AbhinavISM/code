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
int findMSB(int x){
	int ans = -1;
	for(int j = 0; j<32; j++){
		if(x&(1ll<<j)) {
			ans = j;
		}
	}
	return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		vector<int> w(n,0);
		vector<int> prexor(n, 0);
		for(int i = 0; i<n; i++){
			cin>>w[i];
			if(i-1>=0) prexor[i] = (w[i]^prexor[i-1]);
			else prexor[i] = w[i];
		}
		vector<int> msb(n);
		for(int i = 0; i<n; i++){
			msb[i] = findMSB(w[i]);
		}
		vector<vector<int>> pre(n, vector<int>(32, -1));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<32; j++){
				if(i-1>=0) pre[i][j] = pre[i-1][j];
			}
			for(int k = 0; k<=msb[i]; k++){
				pre[i][k] = i;
			}
		}
		while(q--){
			int x;
			cin>>x;
			int xmsb = findMSB(x);
			int score = 0;
			int hi = n-1;
			for(int j = 0; j<32; j++){
				// ran this loop 64 times instead of 32 because of the way 
				// i was handling the last else block.
				// i was letting the loop run again after setting hi = pre[hi][xmsb]
				// essentially leaving it for being handled by the second else block in the next iteration.
				// so it took two iterations to handle that last block condition actually.	 

				// if i put all the code of the second block in the last else block too, then i will get away
				// with running the loop only 32 times, as i would have completely handled
				// current xmsb condition, and there can only be 32 different xmsb..
				if(pre[hi][xmsb] == -1) {
					score += (hi + 1);
					break;
				} else if(pre[hi][xmsb]==hi){
					if(w[hi] <= x){
						score++;
						x = w[hi]^x;
						hi--;
						if(hi==-1) break;
						xmsb = findMSB(x);
						if(xmsb==-1) break;
					} else {
						break;
					}
				} else {
					score += (hi - pre[hi][xmsb]);
					x = x^(prexor[hi]^prexor[pre[hi][xmsb]]);
					hi = pre[hi][xmsb];
					xmsb = findMSB(x);
					
					//added the code of 2nd block here
					if(w[hi] <= x){
						score++;
						x = w[hi]^x;
						hi--;
						if(hi==-1) break;
						xmsb = findMSB(x);
						if(xmsb==-1) break;
					} else {
						break;
					}
				}
			}
			cout<<score<<" ";
		}
		cout<<"\n";
	}
	return 0;
}