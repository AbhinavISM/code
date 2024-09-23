#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int MOD = 1000000007;
int calfactorial[1001] = {0};
void precalfact(){
    calfactorial[0] = 1;
    for(int i = 1; i<1001; i++){
        calfactorial[i] = i*calfactorial[i-1];
        calfactorial[i]%=MOD;
    }
}
int binexp(int x, int y){
    int ans = 1;
    while(y>0){
        if(y%2!=0) {
            ans *= x;
            ans = ans%MOD;
        }
        x = (x*x)%MOD;
        y = y/2;
    }
    //cout<<"binexp"<<ans<<" ";
    return ans%MOD;
}
int ncr(int n, int r){
    if(r>n){
        return 0;
    }
    int num = calfactorial[n];
    int den = (calfactorial[r]*calfactorial[n-r]);
    den%=MOD;
    int deninverse = binexp(den,MOD-2);
    // cout<<"ncr"<<(deninverse*num)%MOD<<" ";
    return (deninverse*num)%MOD;
}

int32_t main() {
    precalfact();
    int k;
    cin>>k;
    vector<int> colorsfreq(k+1,0);
    vector<int> colorsfreqsums(k+1,0);
    for(int i = 1; i<=k; i++){
        int item;
        cin>>item;
        colorsfreq[i] = item;
        colorsfreqsums[i] = item + colorsfreqsums[i-1];
    }
    vector<int> dp(k+1,0);
    dp[1] = 1;
    int ans = 1;
    for(int i = 2; i<=k; i++){
        // cout<<colorsfreqsums[i]<<" "<<colorsfreq[i]-1;
        dp[i] = ncr(colorsfreqsums[i]-1,colorsfreq[i]-1);
        ans *= dp[i];
        ans %= MOD;
    }
    cout<<ans;
    return 0;
}