#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
const int mod = 1e9 + 7;

int maxSubArraySum(vector<int> &a, int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

long long power(long long a, long long b)
{
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,k;
	cin>>n>>k;
	vector<int> a(n,0);
	int ans = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		ans += a[i];
		ans%=mod;
	}
	int max_sum = maxSubArraySum(a, n);
	if(max_sum<0) {max_sum = 0;}
	int tmp = max_sum;
	for(int i = 1; i<=k; i++){
		max_sum = (max_sum*power(2,1));
		max_sum %= mod;
	}
	max_sum -= tmp;
	ans += max_sum;
	ans %= mod;
	ans = (ans + mod)%mod;
	cout<<ans<<"\n";
}
	return 0;
}