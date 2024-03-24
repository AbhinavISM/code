#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int MOD = 1000000007;
int mul(int x, int y){
    return (x * 1ll * y)%MOD;
}
int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y&1)z=mul(z, x);
        x=mul(x, x);
        y>>=1;
    }
    return z;
}
int ans(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return 0;
    }
    if(n==2&&x==2){
        return 1;
    }
	return (n-1)*(binpow(n-2,x-2));
}
int32_t main(){
	fast_io;
	int n,x;
	cin>>n>>x;
	cout<<ans(n,x);
}