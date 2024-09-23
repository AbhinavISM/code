#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
const int MOD = 998244353;

int stab(int x){
    while(x<0)x+=MOD;
    while(x>=MOD)x-=MOD;
    return x;
}

int add(int x, int y){
    x += y;
    return stab(x);                         
}

int sub(int x, int y){
    return add(x, MOD - y);
}

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

int inv(int x){
    return binpow(x, MOD - 2);   
}

int divide(int x, int y){
    return mul(x, inv(y));
}
vector<int> fact,invfact;

void factorial(int N){
    fact.resize(N+1);
    invfact.resize(N+1);
    
    fact[0]=1;
    for(int i=1;i<=N;i++)fact[i]=mul(i,fact[i-1]);
    
    invfact[N]=inv(fact[N]);
    for(int i=N;i;--i)invfact[i-1]=mul(i,invfact[i]);
}

int ncr(int n,int m){
    //remember to initialize factorial()
    if(m>n || m<0)return 0;//or assert
    return mul(fact[n],mul(invfact[n-m],invfact[m]));
}
int32_t main(){
	fast_io;
	factorial(1000001);
	int t;
	cin>>t;
	while(t--){
	int l,r;
	cin>>l>>r;
	int p2 = 0;
	while((l<<p2)<=r){
		p2++;
	}
	cout<<p2<<" ";
	int ans = 0;
	int cnt = 0;
	bool first = true;
	while(p2>=1){
		int hi = r;
		int lo = l;
		int maxmid = l-1;
		while(hi>=lo){
			int mid = lo + (hi-lo)/2;
			if((mid<<(p2-1))*(binpow(3,cnt))<=r){
				lo = mid + 1;
				maxmid = max(maxmid, mid);
			} else {
				hi = mid - 1;
			}
		}
		if(!first) {ans += (maxmid - l + 1)*(p2); break;}
		else {ans += (maxmid - l + 1); first = false;}
		ans %= MOD;
		p2--;
		cnt++;
	}
	cout<<ans<<"\n";
}
	return 0;
}