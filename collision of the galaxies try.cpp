#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
    // Initialize result as n
    int result = n; 
  
    // Consider all prime factors of n 
    // and subtract their multiples 
    // from result
    for(int p = 2; p * p <= n; ++p)
    {
         
        // Check if p is a prime factor.
        if (n % p == 0) 
        {
             
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
  
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
         
    return result;
}
int power(long long x, unsigned int y, int p) 
{ 
    int res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
}
int factorial(int x, int mod){
	int ans = 1;
	for(int i = 1; i<=x; i++){
		ans *= i;
		ans%=mod;
	}
	return ans;
}
int modinv(int x, int mod){
	// if(mod==100000){cout<<x<<" "<<phi(mod)-1<<" ";}
	int ans = power(x, (phi(mod)-1), mod);
	// if(mod==100000){cout<<ans<<" ";}
	return ans;
}
int main(){
	int n;
	cin>>n;
	map<int,map<int,int>> ss;
	for(int i = 1; i<=n; i++){
		int size;
		cin>>size;
		if(ss.find(size)!=ss.end()){
			ss[size][i]++;
		} else {
			map<int,int> temp;
			temp[i]++;
			ss[size] = temp;
		}
	}
	for(int i = 1; i<=n; i++){
		int size;
		cin>>size;
		if(ss.find(size)!=ss.end()){
			ss[size][i]++;
		} else {
			map<int,int> temp;
			temp[i]++;
			ss[size] = temp;
		}
	}
	int mod;
	cin>>mod;
	int ans = 1;
	for(auto it : ss){
		int total = 0;
		int divideby = 1;
		for(auto it2 : it.second){
			total+=it2.second;
			divideby *= factorial(it2.second, mod);
			divideby%=mod;
		}
		int totfact = factorial(total, mod);
		int inv = modinv(divideby, mod);
		// cout<<divideby<<" "<<mod<<" ";
		// cout<<totfact<<" "<<inv<<"\n";
		ans *= (totfact*inv);
		ans%=mod;
	}
	cout<<ans<<"\n";
	// cout<<ans;
	// for(auto it : ss){
	// 	cout<<it.first<<"\n";
	// 	for(auto it2 : it.second){
	// 		cout<<it2.first<<" "<<it2.second<<"\n";
	// 	}
	// }
	return 0;
}