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
// Recursive function to return gcd of a and b 
long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int32_t main(){
	fast_io;
	int n = 200000;
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
	    if (is_prime[i] && (long long)i * i <= n) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1,0);
		vector<int> f(n+1,0);
		for(int i = 1; i<=n; i++){
			cin>>a[i];
			f[a[i]]++;
		}
		
		vector<bool> is_semi_prime(n+1, false);
		vector<int> m(n+1,0); //count of semi primes containing prime 'i'
		for(int i = 1; i<=n; i++){
			for(int d = 2; d*d<=a[i]; d++){
				if(is_prime[d]){
					if(a[i]%d==0){
						if(is_prime[a[i]/d]){
							is_semi_prime[a[i]] = true;
							m[d]++;
							if(d*d!=a[i]) m[a[i]/d]++;
						}
					}
				}
			}
		}

		vector<int> primes_ahead(n+1, 0);
		for(int i = n-1; i>=1; i--){
			if(is_prime[a[i+1]]){
				primes_ahead[i] = primes_ahead[i+1] + 1;
			} else {
				primes_ahead[i] = primes_ahead[i+1];
			}
		}

		int ans = 0;
		
		for(int i = 1; i<=n; i++){
			if(is_prime[a[i]]){
				ans += primes_ahead[i];
			}
			if(is_prime[i]){
				ans -= (f[i]*(f[i]-1))/2;
			}
		}

		for(int i = 1; i<=n; i++){
			if(is_semi_prime[i]){
				if(f[i] > 0){
					ans += (f[i]*(f[i]+1))/2;
				}
			}
		}

		for(int i = 1; i<=n; i++){
			if(is_prime[a[i]]) ans += m[a[i]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}