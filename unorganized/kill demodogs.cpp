#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int mod = 1000000007;
int binexp(int x, int y){
    int ans = 1;
    while(y>0){
        if(y%2!=0) {
            ans *= x;
            ans = ans%mod;
        }
        x = (x*x)%mod;
        y = y/2;
    }
    //cout<<"binexp"<<ans<<" ";
    return ans%mod;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	// cout<<n<<" ";
	int a = (((((n*(n+1))%mod)*(2*n+1))%mod)*binexp(6, mod-2))%mod;
	int b = (((((n*(n-1))%mod)*(2*n-1))%mod)*binexp(6, mod-2))%mod;
	int c = (((n*(n-1))%mod)*binexp(2, mod-2))%mod;
	// cout<<a<<b<<c<<" ";
	cout<<(((a+b+c)%mod)*2022)%mod<<"\n";
}
	return 0;
}