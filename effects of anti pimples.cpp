#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int mod = 998244353;
int binexp(int x, int n){
	if(n==0){
		return 1;
	}
	int a = binexp(x,n/2);
	if(n%2){
		return (x*(a*a)%mod)%mod;
	} else {
		return (a*a)%mod;
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> array(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> maxofmultiples(n+1);
	for(int i = 1; i<=n; i++){
		int maxi = INT_MIN;
		for(int j = i; j<=n; j+=i){
			maxi = max(array[j],maxi);
		}
		maxofmultiples[i] = maxi;
	}
	sort(maxofmultiples.begin()+1, maxofmultiples.end(),greater<int>());
	// for(int i = 1; i<=n; i++){
	// 	cout<<maxofmultiples[i]<<" ";
	// }
	// cout<<"\n";
	int twokipowern = binexp(2,n-1);
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans = (ans + (maxofmultiples[i]*binexp(2,n-i))%mod)%mod;
		// ans%=mod;
		// twokipowern/=2;
	}
	cout<<ans;
	return 0;
}