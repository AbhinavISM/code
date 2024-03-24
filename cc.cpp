#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
    fast_io;
    int t;
    cin>>t;
    int s;
    cin>>s;
    while(t--){
    int n;
    cin>>n;
    vector<int> array;
    for(int i = 0; i<n; i++){
        int item;
        cin>>item;
        array.push_back(item);
    }
    sort(array.begin(), array.end());
    if(s==0){
        int ans = 0;
        int r = (n+1)/2;
        if(n%2){
            for(int i = 0; i<r; i++){
                ans+=array[i];
            }
        } else {
            for(int i = 1; i<=r; i++){
                ans+=array[i];
            }
        }
        cout<<ans<<"\n";
    } else {
        vector<int> prefix(n+1,0);
        for(int i = 1; i<=n; i++){
            prefix[i] = prefix[i-1] + array[i-1];
        }
        int ans = 0;
        for(int i = n; i>=1; i--){
            int lo = i;
            int hi = i + (n-i)/2;
            ans = max(ans, prefix[hi] - prefix[lo-1]);
        }
        cout<<ans<<"\n";
    }
}
    return 0;
}