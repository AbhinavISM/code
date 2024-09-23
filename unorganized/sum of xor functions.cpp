#include<bits/stdc++.h>
#define int unsigned long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	// int t;
	// cin>>t;
	// while(t--){
	int n;
	cin>>n;
	vector<int> array(n+1);
	int allxor = 0;
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
		allxor ^= item;
	}
	int fans = 0;
	for(int i = 1; i<=n; i++){
		int ans = 0;
		ans += ((i*n-i*i)%998244353);
		ans%=998244353;
		ans += i;
		ans%= 998244353;
		ans *= allxor;
		ans%= 998244353;
		allxor ^= array[i];
		fans+=ans;
		fans%= 998244353;
	}
	cout<<fans<<"\n";
// }
	return 0;
}