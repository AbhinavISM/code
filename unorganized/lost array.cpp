#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int MOD = 1000000007;
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
int solve(int i, int l, int r, int previousSum){
    if(i==0){
        if(previousSum%3==0){
            return 1;
        } else {
            return 0;
        }
    }
    int ans =  0;
    if(n0>0) ans += (n0*solve(i-1,l,r,(previousSum+0)%3));
    if(n1>0) ans += (n1*solve(i-1,l,r,(previousSum+1)%3));
    if(n2>0) ans += (n2*solve(i-1,l,r,(previousSum+2)%3));
    return ans;
}
int32_t main() {
    int n;
    cin>>n;
    int l;
    cin>>l;
    int r;
    cin>>r;
    n0 = (int)floor((r)/3)-(int)ceil((l)/3)+1;
    n1 = (int)floor((r-1)/3)-(int)ceil((l-1)/3)+1;
    n2 = (int)floor((r-2)/3)-(int)ceil((l-2)/3)+1;
    // int lb=0;
    // int ub=0;
    // for(int i = l; i<=r; i++){
    //     if(i%3==0){
    //         lb = i;
    //         break;
    //     } else if(i%3==1){
    //         n1++;
    //     } else {
    //         n2++;
    //     }
    // }
    // for(int i = r; i>=l+2; i++){
    //     if(i%3==0){
    //         ub = i;
    //         break;
    //     } else if(i%3==1){
    //         n1++;
    //     } else {
    //         n2++;
    //     }
    // }
    // if(lb==0) {n0 = 0;}
    // else {n0 = (ub/3-lb/3+1);}
    // n1+=(ub-lb-n0+1)/2;
    // n2+=(ub-lb-n0+1)/2;
    cout<<n0<<" "<<n1<<" "<<n2<<" ";
    cout<<solve(n,l,r,0);
    return 0;
}