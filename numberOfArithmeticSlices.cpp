#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
    fast_io;
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i = 1; i<=n; i++){
        int item;
        cin>>item;
        nums[i] = item;
    }
    vector<map<int,int>> dp(n+1, map<int,int>());
    for(int i = 2; i<=n; i++){
        for(int j = i-1; j>=1; j--){
            int diff = nums[i] - nums[j];
            if(dp[j].find(diff)==dp[j].end()){
                dp[j][diff] = 1;
                if(i==4&&j==3){cout<<"ayein";}
            }
            dp[i][diff] = 1 + dp[j][diff];
            if(i==4&&j==3)cout<<dp[i][diff]<<" ";
        }
        cout<<"\n";
    }
    int ans = 0;
    for(auto it1 : dp){
        for(auto it2 : it1){
            if(it2.second>=3){
                ans+=(it2.second-2);
            }
        }
    }
    // cout<<ans;
}