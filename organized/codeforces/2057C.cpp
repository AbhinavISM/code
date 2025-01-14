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
int xors(int a, int b, int c){
	return (a^b) +  (b^c) + (a^c);
}
int32_t main(){
	// cout<<2*(20^3);
	// cout<<(7^16)+(7^11)+(11^16);
	// return 0;
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		if(r-l<=16){
			int a,b,c;
			int maxi = INT_MIN;
			for(int i = l; i<=r; i++){
				for(int j = i+1; j<=r; j++){
					for(int k = j+1; k<=r; k++){
						if(xors(i,j,k)>=maxi){
							maxi = xors(i,j,k);
							// if(i==0&&j==3&&k==4) cout<<maxi<<" ";							
							a = i; b = j; c = k;
						}
					}
				}
			}
			cout<<a<<" "<<b<<" "<<c<<"\n";
			continue;
		}
		int tmp = l;
		vector<int> lbit;
		while(tmp>0){
			lbit.push_back(tmp%2);
			tmp/=2;
		}

		tmp = r;
		vector<int> rbit;
		while(tmp>0){
			rbit.push_back(tmp%2);
			tmp/=2;
		}

		for(int i = lbit.size(); i<rbit.size(); i++){
			lbit.push_back(0);
		}
		reverse(lbit.begin(), lbit.end());
		reverse(rbit.begin(), rbit.end());	

		// peek(rbit) peek(lbit)

		int i = 0;
		while(lbit[i]==rbit[i]){
			i++;
		}
		if(lbit[i]==0){
			vector<int> abit;
			for(int j = 0; j<i; j++){
				abit.push_back(rbit[j]);
			}
			abit.push_back(1);
			for(int j = i+1; j<rbit.size(); j++){
				abit.push_back(0);
			}
			reverse(abit.begin(), abit.end());
			int a1 = 0; int a2 = 0; int a3 = 0;
			for(int j = 0; j<rbit.size(); j++){
				a1 += (abit[j])*(1<<j);
			}
			if(a1-2>=l) cout<<a1<<" "<<a1-1<<" "<<a1-2<<"\n";
			else cout<<a1<<" "<<a1-1<<" "<<a1+1<<"\n";
		}
	}
	return 0;
}