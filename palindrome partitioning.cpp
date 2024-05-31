#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i : v) {for(auto j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
class Solution {
public:
	void rec(string &s, int i, int n, vector<string> parts,
	 vector<vector<string>> &ans){
	 	if(i==n){
	 		ans.push_back(parts);
	 	}
	 	int j;
	 	for(j = i; j<n; j++){
	 		bool good = true;
	 		int t1 = i;
	 		int t2 = j;
	 		while(t1<t2){
	 			if(s[t1]==s[t2]) {
	 				t1++;t2--;
	 			} else {
	 				good = false;
	 				break;
	 			}
	 		}
	 		if(good){
	 			parts.push_back(s.substr(i,j-i+1));
	 			rec(s,j+1,n,parts,ans);
	 			parts.pop_back();
	 		}
	 	}
	}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        rec(s,0,s.length(),vector<string>(),ans);
        return ans;
    }
};
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	string s;
	cin>>s;
	dpeek(Solution().partition(s));
}
