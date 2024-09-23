#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<bool> sums(100001,0);
vector<bool> dp(101,0);
void solve(int i, vector<int> &coins){
    if(i==-1){
        return;
    }
    if(dp[i]){
        return;
    }
    dp[i] = 1;
    solve(i-1,coins);
    for(int j = 100000; j>=0; j--){
        if(sums[j]){
            sums[j+coins[i]] = 1;
        }
    }
}
int32_t main() {
    fast_io;
    sums[0] = 1;
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i = 0; i<n; i++){
        int item;
        cin>>item;
        coins[i] = item;
    }
    solve(n-1,coins);
    cout<<count(sums.begin(), sums.end(), true)-1<<"\n";
    for(int i = 1; i<=100000; i++){
        if(sums[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}
