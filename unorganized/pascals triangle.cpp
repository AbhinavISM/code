#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        for(int i = 0; i<numRows; i++){
            ans[i] = vector<int>(i+1,0);
            for(int j = 0; j<ans[i].size(); j++){
                if(j-1>=0) ans[i][j] += ans[i-1][j-1];
                if(j<ans[i-1].size()) ans[i][j] += ans[i-1][j];
            }
        }
    }
};