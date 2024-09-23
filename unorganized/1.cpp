#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int32_t main() {
    int n;
    cin>>n;
    int dp[n+1] = {0};
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        int temp = i;
        int mini = 1e9;
        while(temp!=0){
            if(temp%10==0){
                temp=temp/10;
                continue;
            }
            if(i-temp%10<0){
                temp=temp/10;
                continue;
            }
            if(dp[i-temp%10]<mini){
                mini = dp[i-temp%10];
            }
            temp=temp/10;
        }
        if(mini!=1e9)
        dp[i] = mini+1;
    }
    cout<<dp[n];
    return 0;
}
