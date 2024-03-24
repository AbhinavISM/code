#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int32_t main() {
    int t;
    cin>>t;
while(t--){
    int n;
    cin>>n;
    int m;
    cin>>m;
    string s;
    cin>>s;
    vector<int> prefixsum(n,0);
    prefixsum[0] = ((int)s[0])-48;
    for(int i = 0; i<n; i++){
        if(((int)s[i])-48){
            s[i] = s[i-1];
        } else {
            s[i] = s[i-1] + 1;
        }
    }
    for(int i = 0; i<m; i++){
        int l;
        cin>>l;
        int r;
        cin>>r;

    }
    //sort(healths.begin(), healths.end(), cmp);

}
}
