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
	vector<bool> prime(200001, true);
	for (int p = 2; p * p <= 200000; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= 200000; i += p)
			prime[i] = false;
		}
	}
	vector<int> allPrimes;
	for(int i = 2; i<=200000; i++){
		if(prime[i]) allPrimes.push_back(i);
	}
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	vector<map<int, int>> allpfact(n);
	for(int i = 0; i<n; i++){
		map<int, int> pfact;
		for(int j = 0; j<allPrimes.size()&&allPrimes[j]*allPrimes[j]<=a[i]; j++){
			while(a[i]%allPrimes[j]==0){
				pfact[allPrimes[j]]++;
				a[i]/=allPrimes[j];
			}
		}
		if(a[i]>1) pfact[a[i]]++;
		allpfact[i] = pfact;
	}
	int ans = 1;
	for(int p : allPrimes){
		int mini = INT_MAX;
		int smini = INT_MAX;
		for(map<int, int> pfact : allpfact){
			if(mini>pfact[p]){
				smini = mini;
				mini = pfact[p];
			} else if(smini>pfact[p]){
				smini = pfact[p];
			}
		}
		int maxi = max(mini, smini);
		for(int i = 0; i<maxi; i++){
			ans *= p;
		}
	}
	cout<<ans<<"\n";

	return 0;
}
