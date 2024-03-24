// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int binexp(int x, int y){
    int ans = 1;
    while(y>0){
        if(y%2!=0){
            ans *= x;
            ans = ans%mod;
        }
        x *= x;
        x %= mod;
        y /= 2;
    }
    return ans%mod;
}
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1;
            continue;
        }
        if(n%2==0){
            cout<<binexp(2,n/2)<<"\n";
        } else {
            cout<<binexp(2,(n/2))<<"\n";
        }
    }
    return 0;
}  