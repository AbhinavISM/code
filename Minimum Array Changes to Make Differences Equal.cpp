#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();

        int lull = abs(nums[0]-nums[n-1]);
        bool gull = true;
        for(int i = 0;i<n; i++){
            if(abs(nums[i]-nums[n-i-1])!=lull) gull = false;
        }
        if(gull){
            return 0;
        }
        
        vector<int> f(8,0);
        for(int i = 0; i<n/2; i++){
            int j = n-i-1;
            f[abs(nums[i]-nums[j])]++;
        }
        peek(f)
        vector<int> rf(8, 0);
        for(int i = 0; i<n/2; i++){
            int j = n-i-1;
            int a = max(0ll,max(nums[i]-1,max(k-nums[i],max(nums[j]-1,k-nums[j]))));
            // cout<<a<<" ";
            rf[a+1]--;
            rf[0]++;
        }
        for(int i = 1; i<8; i++){
            rf[i] += rf[i-1];
        }
        peek(rf)
        int ans = INT_MAX;
        for(int d = 0; d<=k; d++){
            int tans = 0;
            int tosub = 0;
            int tn = n;
            tn/=2;
            tosub += f[d];
            rf[d] -= tosub;
            tn -= f[d];
            // if(d==4){
            //     cout<<rf[d]<<" "<<tn<<"\n";
            // }
            if(tn>=rf[d]){
                tans += rf[d];
                tn -= rf[d];
                tans += tn*2;
            } else {
                tans += tn;
            }
            ans = min(ans, tans);
        }
        return ans;
    }
};

int32_t main(){
    fast_io;
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<Solution().minChanges(a,k);
}